#include<bits/stdc++.h>
using namespace std;
 
vector<int> visited(7,0);
vector<vector<int>> Graph = {
    {0,1,1,0,0,0,0},
    {1,0,1,0,0,0,1},
    {1,1,0,0,0,0,1},
    {0,0,0,0,1,1,1},
    {0,0,0,1,0,1,1},
    {0,0,0,1,1,0,0},
    {0,1,1,1,1,0,0} 
};
vector<int> print;
 
void DFS(int i) {
    cout << "Current: " << i << endl;
    visited[i] = 1;
    if(find(print.begin(), print.end(), i) == print.end())
        print.push_back(i);
    cout << "Visited: ";
    for(int k: print) {
        cout << k << " ";
    }
    cout << endl << endl;
    for (int j = 0; j < 7; j++) {
        if(Graph[i][j]==1 && visited[j]==0){
            print.push_back(j);
            DFS(j);
        }
    }
}
 
int main() { 
    int in;
    cout << "Enter the starting vertex:" << endl;
    cin >> in;
    cout << endl << "--------DFS Algorithm--------" << endl;
    DFS(in); 
    return 0;
}