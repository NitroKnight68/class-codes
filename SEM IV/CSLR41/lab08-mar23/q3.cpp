#include <bits/stdc++.h>

using namespace std;

int memoizationMCM(vector<int>& dimensions, int i, int j, vector<vector<int>>& dpTable) {
    if (i == j) {
        return 0;
    }

    if (dpTable[i][j] != -1) {
        return dpTable[i][j];
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; ++k) {
        minCost = min(memoizationMCM(dimensions, i, k, dpTable) +
                   memoizationMCM(dimensions, k+1, j, dpTable) +
                   dimensions[i-1] * dimensions[k] * dimensions[j], minCost);
    }

    dpTable[i][j] = minCost;
    return minCost;
}


int main() {
    int n;
    cout << "Enter the number of matrices: " << endl;
    cin >> n;
    cout << endl;

    cout << "Enter the dimensions of the matrices: " << endl;
    vector<int> dimensions(++n);
    for(int i = 0; i < n; i++) {
        cout << "d" << i << " -> ";
        cin >> dimensions[i];
    }

    vector<vector<int>> dpTable(dimensions.size(), vector<int>(dimensions.size(), -1));
    cout << endl << "Least number of scalar multiplications is " << memoizationMCM(dimensions, 1, dimensions.size()-1, dpTable) << endl;

    return 0;
}