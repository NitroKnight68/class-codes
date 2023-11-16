import numpy as np
import skfuzzy as fuzz
from skfuzzy.cluster import cmeans
import pandas as pd
import matplotlib.pyplot as plt

iris_df = pd.read_csv('iris.csv')
X = iris_df[['SepalLengthCm', 'SepalWidthCm', 'PetalLengthCm', 'PetalWidthCm']].values.T

# Fuzzy Clustering
cntr, u, u0, d, jm, p, fpc = cmeans(X, c=3, m=2, error=0.005, maxiter=1000)
cluster_membership = np.argmax(u, axis=0)

# Plotting Results
plt.figure(figsize=(8, 6))
for j in range(3):
    plt.scatter(X[0, cluster_membership == j],
                X[1, cluster_membership == j],
                label=f'Cluster {j}')

plt.scatter(cntr[:, 0], cntr[:, 1], s=200, marker='P', c='r', label='Centers')
plt.title('Fuzzy Clustering of Iris Dataset')
plt.xlabel('Sepal Length (cm)')
plt.ylabel('Sepal Width (cm)')
plt.legend()
plt.show()
