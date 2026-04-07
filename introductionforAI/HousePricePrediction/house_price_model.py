import pandas as pd
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.impute import SimpleImputer
from sklearn.pipeline import Pipeline
from torch.utils.data import TensorDataset, DataLoader

# 加载数据
train_df = pd.read_csv('data/train.csv')
test_df = pd.read_csv('data/test.csv')

# 分离特征与标签，并对房价取对数
X = train_df.drop(columns=['Id', 'SalePrice'])
y = np.log1p(train_df['SalePrice'])
X_test = test_df.drop(columns=['Id'])

# 划分数值型和类别型特征
num_features = X.select_dtypes(include=[np.number]).columns.tolist()
cat_features = X.select_dtypes(exclude=[np.number]).columns.tolist()

# 构建预处理管道
num_pipeline = Pipeline([
    ('imputer', SimpleImputer(strategy='median')),
    ('scaler', StandardScaler())
])

cat_pipeline = Pipeline([
    ('imputer', SimpleImputer(strategy='constant', fill_value='Missing')),
    ('onehot', OneHotEncoder(handle_unknown='ignore', sparse_output=False))
])

preprocessor = ColumnTransformer([
    ('num', num_pipeline, num_features),
    ('cat', cat_pipeline, cat_features)
])

# 拟合并转换训练集与测试集
X_processed = preprocessor.fit_transform(X)
X_test_processed = preprocessor.transform(X_test)

# 划分训练集和验证集
X_train, X_val, y_train, y_val = train_test_split(
    X_processed, y.values, test_size=0.2, random_state=42
)

# 转换为 PyTorch 张量
X_train_t = torch.tensor(X_train, dtype=torch.float32)
y_train_t = torch.tensor(y_train, dtype=torch.float32).reshape(-1, 1)
X_val_t = torch.tensor(X_val, dtype=torch.float32)
y_val_t = torch.tensor(y_val, dtype=torch.float32).reshape(-1, 1)
X_test_t = torch.tensor(X_test_processed, dtype=torch.float32)

# 定义神经网络模型
class HousePriceNN(nn.Module):
    def __init__(self, input_dim, dropout_rate=0.1):
        super().__init__()
        self.fc1 = nn.Linear(input_dim, 128)
        self.fc2 = nn.Linear(128, 64)
        self.fc3 = nn.Linear(64, 1)
        self.dropout = nn.Dropout(dropout_rate)
        self.relu = nn.ReLU()

    def forward(self, x):
        x = self.relu(self.fc1(x))
        x = self.dropout(x)
        x = self.relu(self.fc2(x))
        x = self.dropout(x)
        x = self.fc3(x)
        return x

# 初始化模型
model = HousePriceNN(input_dim=X_train.shape[1])

# 设置损失函数和优化器
criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

# 创建数据加载器
train_dataset = TensorDataset(X_train_t, y_train_t)
train_loader = DataLoader(train_dataset, batch_size=32, shuffle=True)

# 训练模型
model.train()
for epoch in range(10):
    total_loss = 0
    for batch_X, batch_y in train_loader:
        optimizer.zero_grad()
        outputs = model(batch_X)
        loss = criterion(outputs, batch_y)
        loss.backward()
        optimizer.step()
        total_loss += loss.item()
    avg_loss = total_loss / len(train_loader)

# 对测试集进行预测
model.eval()
with torch.no_grad():
    test_preds = model(X_test_t).numpy().flatten()

# 将预测结果还原为原始房价尺度
final_preds = np.expm1(test_preds)

# 生成提交文件
submission = pd.DataFrame({
    'Id': test_df['Id'],
    'SalePrice': final_preds
})
submission.to_csv('submission.csv', index=False)