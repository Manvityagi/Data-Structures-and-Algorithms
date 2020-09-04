// finding the lengths of the shortest paths
// from a starting vertex s to all other vertices, and output the shortest paths themselves.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int v, e;
vector<pair<int, int>> g[N];
// src -> (weight,dest)

void bfs(){
    vector<int> visited(v, 0);
    set<pair<int, int>> q;
    vector<int> dis(v, INT_MAX);
    q.emplace(0, 0);
    while (!q.empty()){
        int src = q.begin()->second;
        q.erase(q.begin());
        if (visited[src]) continue;
        visited[src] = 1;

        for (auto u : g[src]) {
            int dest = u.second, wt = u.first;
            if (visited[dest]) continue;

            if (dis[dest] > dis[src] + wt) {
                dis[dest] = dis[src] + wt;
                q.emplace(dis[dest], dest);
            }
        }
    }
}

int main() {
    cin >> v>> e;
    for (int i = 0; i < e; i++) {
        int src, dest, wt;
        cin >> src >> dest;
        g[src].emplace_back(dest);
        g[dest].emplace_back(src);
    }
    bfs();
}