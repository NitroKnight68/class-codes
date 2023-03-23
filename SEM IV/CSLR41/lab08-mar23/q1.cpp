#include <bits/stdc++.h>

using namespace std;

int iterativeMCM(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> MCM(n+1, vector<int>(n+1, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            MCM[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = MCM[i][k] + MCM[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];
                if (q < MCM[i][j]) {
                    MCM[i][j] = q;
                }
            }
        }
    }

    return MCM[1][n];
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

    cout << endl << "Least number of scalar multiplications is " << iterativeMCM(dimensions) << endl;

    return 0;
}