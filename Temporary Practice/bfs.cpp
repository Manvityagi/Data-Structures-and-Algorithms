#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int v, e;
vector<int> g[N];
void bfs()
{
    vector<int> visited(v, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto u : g[front]){
            if(visited[u]) continue;
            visited[u] = 1;
            q.emplace(u);
        }
    }
}

int main() {
    cin >> v>> e;
    for (int i = 0; i < e; i++) {
        int src, dest;
        cin >> src >> dest;
        g[src].emplace_back(dest);
        g[dest].emplace_back(src);
    }
    bfs();
}