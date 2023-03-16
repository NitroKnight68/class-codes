#include <bits/stdc++.h>
using namespace std;

vector<int> W(50,0);
vector<int> P(50,0);


void knapsack(int n, int w) {
	int A[n+1][w+1];
	for(int i = 0; i <= w; i++) {
		A[0][i] = 0;
	}
	for(int i = 0; i <= n; i++) {
		A[i][0] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= w; j++) {
			if(W[i] <= j && P[i] + A[i-1][j-W[i]] > A[i-1][j]) {
				A[i][j] = P[i] + A[i-1][j-W[i]];
			}
			else {
				A[i][j] = A[i-1][j];
			}
		}
	}
	cout << "The maximum profit that can fit in the knapsack is " << A[n][w] << endl;
}

int main() {
	int n, w;
	cout << "Enter the number of objects: ";
	cin >> n;
	cout << "Enter the weights of the objects: " << endl;
	for(int i = 1; i <= n; i++) {
		cin >> W[i];
	}
	cout << "Enter the profits of the objects: " << endl;
	for(int i = 1; i <= n; i++) {
		cin >> P[i];
	}
	cout << "Enter the maximum weight of the knapsack: ";
	cin >> w;
	knapsack(n,w);
	return 0;
}
