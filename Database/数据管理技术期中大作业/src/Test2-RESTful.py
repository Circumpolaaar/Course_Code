from flask import Flask, request, jsonify
import pymysql

app = Flask(__name__)
id = 23373428
db = pymysql.connect(
    host="120.46.132.88",
    user=f"{id}",
    password=f"{id}",
    database=f"db_{id}",
    port=3306
)
# db = pymysql.connect(
#     host="localhost",
#     user="root",
#     password="MySQLPassword1231",
#     database="test"
# )


# 插入数据
@app.route('/api/v1/<table_name>', methods=['POST'])
def insert_data(table_name):
    data = request.json
    rows = data['rows']
    cursor = db.cursor()
    for row in rows:
        keys = ', '.join(row.keys())
        values = ', '.join([f"'{value}'" for value in row.values()])

        sql = f'insert into {table_name}({keys}) values({values})'
        cursor.execute(sql)
    db.commit()
    return jsonify({'message': 'data inserted successfully'}), 201


# 更新数据接口
@app.route('/api/v1/<table_name>', methods=['PUT'])
def update_data(table_name):
    data = request.json
    cursor = db.cursor()

    if not data:
        return jsonify({'error': 'Empty JSON body'}), 400

    if table_name in ['employees']:
        key_field = 'emp_no'
        if key_field not in data:
            return jsonify({'error': f'Missing primary key'}), 400
        where_clause = f"{key_field} = '{data[key_field]}'"
        update_fields = [f"{k} = '{v}'" for k, v in data.items() if k != key_field]

    elif table_name == 'departments':
        key_field = 'dept_no'
        if key_field not in data:
            return jsonify({'error': f'Missing primary key'}), 400
        where_clause = f"{key_field} = '{data[key_field]}'"
        update_fields = [f"{k} = '{v}'" for k, v in data.items() if k != key_field]
    # 复合主键(2)
    elif table_name in ['dept_emp', 'dept_manager']:
        if 'emp_no' not in data or 'dept_no' not in data:
            return jsonify({'error': 'Missing composite key'}), 400
        where_clause = f"emp_no = '{data['emp_no']}' AND dept_no = '{data['dept_no']}'"
        update_fields = [f"{k} = '{v}'" for k, v in data.items() if k not in ['emp_no', 'dept_no']]
    # 复合主键(3)
    elif table_name == 'titles':
            if 'emp_no' not in data or 'title'not in data or 'from_date'not in data:
                return jsonify({'error': 'Missing composite key'}), 400
            where_clause = f"emp_no = '{data['emp_no']}' AND title = '{data['title']}' AND from_date = '{data['from_date']}'"
            update_fields = [f"{k} = '{v}'" for k, v in data.items() if k not in ['emp_no', 'title', 'from_date']]    
    else:
        return jsonify({'error': f'Wrong table'}), 400

    if not update_fields:
        return jsonify({'error': 'No fields to update'}), 400

    sql = f"UPDATE {table_name} SET {', '.join(update_fields)} WHERE {where_clause}"

    try:
        cursor.execute(sql)
        db.commit()
        return jsonify({'message': 'Data updated successfully'}), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

# 删除数据
@app.route('/api/v1/<table_name>/<path:args>', methods=['DELETE'])
def delete_data(table_name, args):
    cursor = db.cursor()
    ids = args.split('/')
    # 复合主键(2)
    if table_name in ['dept_emp', 'dept_manager']:
        emp_no = ids[0]
        dept_no = ids[1]
        sql = f"DELETE FROM {table_name} WHERE emp_no = %s AND dept_no = %s"
        cursor.execute(sql, (emp_no, dept_no))
    # 复合主键(3)
    if table_name =='titles':
        emp_no = ids[0]
        title = ids[1]
        from_date = ids[2]
        sql = f"DELETE FROM {table_name} WHERE emp_no = %s AND title = %s AND from_date = %s"
        cursor.execute(sql, (emp_no, title,from_date))
    # 单主键
    elif table_name in ['employees', 'departments', 'dept_manager_title']:
        primary_keys = {
            'employees': 'emp_no',
            'dept_manager_title': 'emp_no',
            'departments': 'dept_no'
        }
        key = primary_keys.get(table_name)
        sql = f"DELETE FROM {table_name} WHERE {key} = %s"
        cursor.execute(sql, (ids[0],))

    db.commit()
    return jsonify({'message': 'data deleted successfully'}), 201

# TODO: finish this fuction to update data

# 查询单条记录
@app.route('/api/v1/<table_name>/<path:args>', methods=['GET'])
def select_data(table_name, args):
    cursor = db.cursor()
    ids = args.split('/')
    
    if table_name in ['dept_emp', 'dept_manager']:
        if len(ids) != 2:
            return jsonify({'error': 'Both emp_no and dept_no are required'}), 400
        sql = f"SELECT * FROM {table_name} WHERE emp_no = '{ids[0]}' AND dept_no = '{ids[1]}'"
    elif table_name in ['employees','dept_manager_title']:
        sql = f"SELECT * FROM {table_name} WHERE emp_no = '{ids[0]}'"
    elif table_name == 'departments':
        sql = f"SELECT * FROM {table_name} WHERE dept_no = '{ids[0]}'"
    elif table_name in ['titles']:
        if len(ids) != 3:
            return jsonify({'error': 'Both emp_no and title and from_date are required'}), 400
        sql = f"SELECT * FROM {table_name} WHERE emp_no = '{ids[0]}' AND title = '{ids[1]}' AND from_date = '{ids[2]}'"
    else:
        sql = f"SELECT * FROM {table_name} WHERE id = '{ids[0]}'"

    try:
        cursor.execute(sql)
        result = cursor.fetchall()
        col_names = [desc[0] for desc in cursor.description]
        data = [dict(zip(col_names, row)) for row in result]
        return jsonify(data), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

# TODO: finish this fuction to update data

# 查询某字段为特定值的记录
@app.route('/api/v1/<table_name>', methods=['GET'])
def select_data_condition(table_name):
    cursor = db.cursor()
    
    if len(request.args) == 0:
        sql = f"SELECT * FROM {table_name}"
    elif len(request.args) == 1:
        key = list(request.args.keys())[0]
        value = request.args.get(key)
        sql = f"SELECT * FROM {table_name} WHERE {key} = '{value}'"
    else:
        return jsonify({'error': 'Too many conditions'}), 400

    try:
        cursor.execute(sql)
        result = cursor.fetchall()
        col_names = [desc[0] for desc in cursor.description]
        data = [dict(zip(col_names, row)) for row in result]
        return jsonify(data), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

# TODO: finish this fuction to update data


if __name__ == '__main__':
    app.run(debug=False, port=5555, host='0.0.0.0')
