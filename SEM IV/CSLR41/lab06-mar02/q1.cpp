#include <bits/stdc++.h>
#include<priority_queue>
using namespace std;

#define SIZE = 6; 

vector<vector<int>> graph = {
    {0,5,10,0,0,0},
    {0,0,0,7,9,0}.
    {0,15,0,20,0,0},
    {0,0,0,0,0,10},
    {0,0,0,8,0,0},
    {0,0,0,0,11,0}
};
vector<int> dist;
vector<bool> visited;

void intialise(vector<vector<int>> graph, int start) {
    for(int i = 0; i < SIZE; i++) {
        if(i != start) {
            dist[i] = INT_MAX;
        }
        else {
            dist[i] = 0;
            visited[i] = 1;
        }
    }
}

void djikstra(vector<vector<int>> graph, int start) {
    int minIndex = 0, minValue = INT_MAX;
    for(int i = 0; i < SIZE; i++) {
        if(!graph[start][j])
            minValue = min(graph[start][j], minValue);
        if(minValue == graph[start][j])
            minIndex = j;
    }
    visited[minIndex] = true;
    dist[minIndex] = dist[start] + minValue;
    start = minIndex;    
}

int main() {
    intialise(graph, start);
    return 0;
}