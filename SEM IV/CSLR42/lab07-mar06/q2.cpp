#include<bits/stdc++.h>
using namespace std;

int n = 5, m = 3;
vector<vector<int>> allocation = {
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};
vector<vector<int>> maxi = {
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};
vector<vector<int>> need;
vector<int> available = {3,3,2};

void bankers()
{
    vector<int> finish(n,0);
    vector<int> safeSeq;
    
    int count = 0;
    while (count < n)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                    {
                        available[k] += allocation[i][k];
                    }
                    safeSeq.push_back(i);
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found)
        {
            cout << "The system not in safe state" << endl;
            return;
        }
    }
    cout << "Safe sequence" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << safeSeq[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> y;
        for (int j = 0; j < m; j++)
        {
            y.push_back(maxi[i][j] - allocation[i][j]);
        }
        need.push_back(y);
    }
    bankers();
    return 0;
}