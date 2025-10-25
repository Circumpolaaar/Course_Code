import requests

BASE_URL = "http://127.0.0.1:5555/api/v1"

# ==================== 辅助函数 ====================
def print_response(operation, resp):
    print(f"\n===> {operation}")
    print(f"Status: {resp.status_code}")
    print("Response:", resp.json() if resp.ok else resp.text)

# ==================== 测试数据 ====================
TEST_DATA = {
    "employees": {
        "valid": {"emp_no": 9999991, "birth_date": "1990-01-01", "first_name": "Test", 
                 "last_name": "User", "gender": "M", "hire_date": "2020-01-01"}
    },
    "departments": {
        "valid": {"dept_no": "d999", "dept_name": "Test Department"}
    },
    "dept_emp": {
        "valid": {"emp_no": 9999991, "dept_no": "d999", "from_date": "2020-01-01", "to_date": "2023-01-01"}
    },
    "title": {
        "valid": {"emp_no": 9999991, "title": "qwer", "from_date": "2020-01-01", "to_date": "2023-01-01"}
    }
}

# # ==================== Employees 表测试 ====================
def test_employees():
    # 插入
    # print_response("插入员工",
    #     requests.post(f"{BASE_URL}/employees", json={"rows": [TEST_DATA["employees"]["valid"]]}))
    
    # 查询
    print_response("查询存在的员工",
        requests.get(f"{BASE_URL}/employees/99999"))
    
    # # 更新
    # update_data = TEST_DATA["employees"]["valid"].copy()
    # update_data["first_name"] = "Updated"
    # print_response("更新员工信息",
    #     requests.put(f"{BASE_URL}/employees", json=update_data))
    
    # # 删除
    # print_response("删除员工",
    #     requests.delete(f"{BASE_URL}/employees/9999991"))

# ==================== Departments 表测试 ====================
def test_departments():
    # # 插入
    # print_response("插入部门",
    #     requests.post(f"{BASE_URL}/departments", json={"rows": [TEST_DATA["departments"]["valid"]]}))
    
    # # 查询
    # print_response("查询存在的部门",
    #     requests.get(f"{BASE_URL}/departments/d999"))
    
    # # 更新
    # update_data = TEST_DATA["departments"]["valid"].copy()
    # update_data["dept_name"] = "Updated Dept"
    # print_response("更新部门信息",
    #     requests.put(f"{BASE_URL}/departments", json=update_data))
    
    # 删除
    print_response("删除部门",
        requests.delete(f"{BASE_URL}/departments/d999"))

# ==================== 复合主键表测试 ====================
def test_composite_keys():
    # 准备基础数据
    requests.post(f"{BASE_URL}/employees", json={"rows": [TEST_DATA["employees"]["valid"]]})
    requests.post(f"{BASE_URL}/departments", json={"rows": [TEST_DATA["departments"]["valid"]]})
    
    # # 部门员工关系测试
    # print_response("插入部门员工关系",
    #     requests.post(f"{BASE_URL}/dept_emp", json={"rows": [TEST_DATA["dept_emp"]["valid"]]}))
    
    # print_response("查询部门员工关系",
    #     requests.get(f"{BASE_URL}/dept_emp/999991/d999"))
    
    # print_response("更新部门员工关系",
    #     requests.put(f"{BASE_URL}/dept_emp", json={"emp_no": 9999991, "dept_no": "d999", "to_date": "2225-01-01"}))
    
    print_response("删除部门员工关系",
        requests.delete(f"{BASE_URL}/dept_emp/9999991/d999"))

# ==================== 触发器测试 ====================
def test_triggers():
    # 插入部门经理
    # print_response("插入部门经理(触发触发器)",
        # requests.post(f"{BASE_URL}/dept_manager", json={"rows": [{
        #     "emp_no": 9999991, 
        #     "dept_no": "d999", 
        #     "from_date": "2020-01-01", 
        #     "to_date": "2023-01-01"
        # }]}))
    
    # print_response("验证触发器-查询经理title",
    #     requests.get(f"{BASE_URL}/dept_manager_title/9999991"))
    
    print_response("删除部门经理(触发触发器)",
        requests.delete(f"{BASE_URL}/dept_manager/9999991/d999"))
    
    print_response("验证触发器删除效果",
        requests.get(f"{BASE_URL}/dept_manager_title/9999991"))

def test_title():
    # 准备基础数据
    requests.post(f"{BASE_URL}/employees", json={"rows": [TEST_DATA["employees"]["valid"]]})
    

    # print_response("插入",
    #     requests.post(f"{BASE_URL}/titles", json={"rows": [TEST_DATA["title"]["valid"]]}))
    
    # print_response("查询",
    #     requests.get(f"{BASE_URL}/titles/9999991/qwer/2020-01-01"))
    
    print_response("更新",
        requests.put(f"{BASE_URL}/titles", json={"emp_no": 9999991, "title": "qwer", "from_date": "2020-01-01","to_date": "2225-01-01"}))
    
    # print_response("删除",
    #     requests.delete(f"{BASE_URL}/titles/9999991/qwer/2020-01-01"))
    
# ==================== 执行所有测试 ====================
if __name__ == "__main__":
    print("=============== 开始全面测试 ===============")
    
    test_employees()
   #  test_departments()
    # test_composite_keys()
   # test_triggers()
    #test_title()
    
    print("=============== 测试完成 ===============")