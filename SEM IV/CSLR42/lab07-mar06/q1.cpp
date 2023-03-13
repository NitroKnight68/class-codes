#include<bits/stdc++.h>
using namespace std;

int n = 5, m = 3;
int allocation[n][m],
allocation = {
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};
int maxi[n][m] = {
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};
int need[n][m];
int available[m] = {3,3,2};

bool bankers()
{
    int finish[n] = {0};
    int safeSeq[n];
    int count = 0, index = 0;
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
                    safeSeq[index++] = i;;
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found)
        {
            cout << "System is not in safe state" << endl;
            return false;
        }
    }
    cout << "System is in safe state" << endl;
    cout << "Safe sequence is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << safeSeq[i] << " ";
    }
    cout << endl;
    return true;
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxi[i][j] - allocation[i][j];
        }
    }
    bankers();
    return 0;
}