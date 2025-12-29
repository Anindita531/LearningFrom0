from sklearn import datasets
from sklearn.svm import SVC
import matplotlib.pyplot as plt

# Simple dataset
X = [[1,2],[2,3],[3,3],[5,4]]
y = [0,0,1,1]  # 0=Apple, 1=Orange

# Train SVM
model = SVC(kernel='linear')
model.fit(X, y)

# Predict
print(model.predict([[4,3]]))  # Predicts class for new point
