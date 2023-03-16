#include <bits/stdc++.h>
using namespace std;

vector<int> W(50,0);
vector<int> P(50,0);

int A[50][50];

int knapsack(int i, int j) {
    if(i == 0 || j == 0) {
        A[i][j] = 0;
    }

    if(A[i][j] != -1) {
        return A[i][j];
    }

    if(W[i] <= j && P[i] + knapsack(i-1,j-W[i]) > knapsack(i-1,j)) {
        A[i][j] = P[i] + knapsack(i-1,j-W[i]);;
        return P[i] + knapsack(i-1,j-W[i]);
    }

    else {
        A[i][j] = knapsack(i-1,j);
        return knapsack(i-1,j);
    }
    return 0;
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

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < w+1; j++) {
            A[i][j] = -1;
        }
    }    
    cout << "The maximum profit that can fit in the knapsack is " << knapsack(n,w) << endl;
	return 0;
}
