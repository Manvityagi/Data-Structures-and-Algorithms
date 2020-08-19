#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int v, e;
vector<int> g[N];
vector<int> visited(N);
bool dfs(int src, int parent){
    for(auto dest : g[src]){
        if(visited[dest] && src != parent) return true;
        if(visited[dest]) continue;
        visited[dest] = 1;
        if(dfs(dest,src)) return true;
    }
    return false;
}

bool isCyclic()
{
    for(int i = 1; i <= v; i++)
        if(!visited[i]){
            bool cycle = dfs(i,-1);
            if(cycle) return true;
        } 
    return false;
}

int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++){
        int src, dest;
        cin >> src >> dest;
        g[src].emplace_back(dest);
        g[dest].emplace_back(src);
    }
    cout << isCyclic() << "\n";
}