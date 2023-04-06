#include <bits/stdc++.h>
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
queue<int> bfsQueue;

int main() {
    int curr;
    int i;
    cout << "Enter the starting node:" << endl;
    cin >> i;
    cout << endl << "--------BFS Algorithm--------" << endl;
    cout << "Current: "<< i << endl;
    visited[i] = 1;
	print.push_back(i);	
    bfsQueue.push(i);
    while (!bfsQueue.empty()) {
        int curr = bfsQueue.front();
        bfsQueue.pop();
        for (int j = 0; j < 7; j++) {
            if(Graph[curr][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                print.push_back(j);
                bfsQueue.push(j);
                cout << "Visited: ";
				for(int k = 0; k < print.size() - 1; k++) {
					cout << print[k] << " ";
				}
                cout << endl << endl;
				cout << "Current: " << j << endl;
            }
        }
        
    }
    cout << "Visited: ";
	for(int k: print) {
		cout << k << " ";
	}
	cout << endl;
    return 0;
}