import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

iris_df = pd.read_csv('iris.csv')
X = iris_df.drop('Species', axis=1)
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# K-Means Clustering
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X_scaled)
iris_df['cluster'] = kmeans.labels_

# Plotting Clusters
plt.figure(figsize=(8, 6))
plt.scatter(X_scaled[:, 0], X_scaled[:, 1], c=kmeans.labels_, cmap='autumn')
centers = kmeans.cluster_centers_
plt.scatter(centers[:, 0], centers[:, 1], c='red', s=200, alpha=0.5)
plt.title("K-Means Clustering of Iris Dataset")
plt.xlabel("Feature 1 after scaling")
plt.ylabel("Feature 2 after scaling")
plt.show()
