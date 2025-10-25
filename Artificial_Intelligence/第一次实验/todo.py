# 实验二
# 根据reg_type(l1, l2)和lambda计算正则项损失reg_loss（通常不对偏置项正则化）
# --------------------------- TODO ---------------------------------------
linear_weight = model.state_dict()['linear.weight']
linear_weight_numpy = linear_weight.numpy()

if reg_type == 'l1':
    reg_loss = lambda_ * np.sum(np.abs(linear_weight_numpy))
elif reg_type == 'l2':
    reg_loss = lambda_ * np.sum(linear_weight_numpy ** 2)
# ------------------------------------------------------------------------

#实验三
def forward(self, x):
    # 将线性结果通过sigmoid得到概率值
    # --------------------------- TODO ---------------------------------------
    probabilities = self.sigmoid(self.linear(x))
    return probabilities
    # ------------------------------------------------------------------------

# 使用二元交叉熵损失
# --------------------------- TODO ---------------------------------------
logits = model(X_tensor)
loss = F.binary_cross_entropy(logits, y_tensor)
# ------------------------------------------------------------------------
            
# 实验四
from sklearn.linear_model import LogisticRegression
from sklearn import metrics

from sklearn.ensemble import GradientBoostingClassifier
from sklearn.metrics import confusion_matrix, classification_report, f1_score

from sklearn.linear_model import SGDClassifier

from sklearn.neural_network import MLPClassifier
import joblib


def train_4_1(X_train_dtm, y_train):
    # 自行探索sklearn库里的Logistic Regression或别的模型，观察效果如何
    model = LogisticRegression(max_iter=300, solver='lbfgs')  
    model.fit(X_train_dtm, y_train)  # 训练模型
    model_path = "sklearn.pkl"
    joblib.dump(model, model_path)  # 保存模型
    print(f"\nLogistic Regression训练完成，模型已保存至：{model_path}")
    
    return model_path

def train_4_2(X_train_dtm, y_train):
    # 使用 GradientBoostingClassifier 模型进行训练
    model = GradientBoostingClassifier(n_estimators=100, max_depth=3, learning_rate=0.1)
    model.fit(X_train_dtm, y_train)   # 训练模型
    model_path = "sklearn_gradient_boosting.pkl"
    joblib.dump(model, model_path)  # 保存模型
    print(f"\nGradientBoostingClassifier 训练完成，模型已保存至：{model_path}")
    
    return model_path

def train_4_3(X_train_dtm, y_train):
    # 使用 SGDClassifier 模型进行训练
    model = SGDClassifier(loss='log', max_iter=1000, learning_rate='optimal')
    model.fit(X_train_dtm, y_train)   # 训练模型
    # 模型路径和保存模型
    model_path = "sklearn_sgd.pkl"
    joblib.dump(model, model_path)  # 保存模型
    print(f"\nSGDClassifier训练完成，模型已保存至：{model_path}")
    
    return model_path

def train_4_4(X_train_dtm, y_train):
    # 创建MLPClassifier模型
    model = MLPClassifier(max_iter=300, solver='adam', hidden_layer_sizes=(100,), activation='relu')
    model.fit(X_train_dtm, y_train)  # 训练模型
    model_path = "mlp_classifier.pkl"
    joblib.dump(model, model_path)  # 保存模型
    print(f"\nMLPClassifier训练完成，模型已保存至：{model_path}")
    
    return model_path

def evaluate_4(model_path, X_test_dtm, y_test):
    model = joblib.load(model_path)  # 加载模型
    y_pred = model.predict(X_test_dtm)  # 预测

    return y_pred

# 训练和评估
functions = [train_4_1, train_4_2, train_4_3, train_4_4]

# 使用for循环依次调用函数
for func in functions:
    model_path = func(X_train_selected, y_train)
    y_pred = evaluate_4(model_path, X_test_selected, y_test)
    # 评估指标输出
    print("\n在测试集上的混淆矩阵：")
    print(metrics.confusion_matrix(y_test, y_pred))

    print("\n在测试集上的分类结果报告：")
    print(metrics.classification_report(y_test, y_pred))

    print("在测试集上的 f1-score：")
    print(metrics.f1_score(y_test, y_pred))

