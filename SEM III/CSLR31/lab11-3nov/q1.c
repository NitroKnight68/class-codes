#include <stdio.h>
#include <stdlib.h>

int i, j, k, u1, v1, u, v, n = 7, edges = 1;
int min, mincost = 0, parent[9];
int cost[7][7] = {
		{0,28,0,0,0,10,0},
		{28,0,16,0,0,0,14},
		{0,16,0,12,0,0,0},
		{0,0,12,0,22,0,18},
		{0,0,0,22,0,25,24},
		{10,0,0,0,25,0,0},
		{0,14,0,18,24,0,0}
};

int find(int i) {
	while (parent[i])
		i = parent[i];
	return i;
}

int uni(int i, int j) {
	if (i != j) {
		parent[j] = i;
		return 1;
	}
	return 0;
}

int main() {
	printf("--------Kruskal's Algorithm--------\n\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	while (edges < n) {
		for (i = 0, min = 999; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (cost[i][j] < min) {
					min = cost[i][j];
					u1 = u = i;
					v1 = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if (uni(u, v)) {
			edges++;
			printf("(%d -> %d) = %d\n", u1+1, v1+1, min);
			mincost += min;
		}
		cost[u1][v1] = cost[v1][u1] = 999;
	}
	printf("\nMinimum cost = %d\n", mincost);
	return 0;
}

