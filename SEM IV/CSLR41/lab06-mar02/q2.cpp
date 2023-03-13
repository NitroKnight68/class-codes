#include <bits/stdc++.h>
using namespace std;

int V = 6;
vector<int> dist(V, INT_MAX);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;


void relax(int u, int v, int weight) {
    if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
    }
}
void djikstra(vector<pair<int, int> > adj[], int V,
                  int src)
{ 
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
 
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            relax(u, v, weight);
        }
    }

    for (int i = 0; i < V; ++i)
        printf("Distance of %d -> %d\n", i, dist[i]);
}
 
int main()
{
    vector<pair<int,int>> adj[V] = {
        {{1,5}, {2,10}},
        {{3,7}, {4,9}},
        {{1,15}, {3,20}},
        {{5,10}},
        {{3,8}},
        {{4,11}}
    };
 
    djikstra(adj, V, 0);
 
    return 0;
}