#include <bits/stdc++.h>

using namespace std;

int recursiveMCM(vector<int>& dimensions, int i, int j) {
    if (i == j) {
        return 0;
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; ++k) {
        minCost = min(recursiveMCM(dimensions, i, k) +
                   recursiveMCM(dimensions, k+1, j) +
                   dimensions[i-1] * dimensions[k] * dimensions[j], minCost);
    }

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

    cout << endl << "Least number of scalar multiplications is " << recursiveMCM(dimensions, 1, dimensions.size()-1) << endl;

    return 0;
}