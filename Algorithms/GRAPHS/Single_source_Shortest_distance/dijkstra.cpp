#include<bits/stdc++.h>
using namespace std;

int v, e;
const int N = 100;
vector<pair<int,int>> g[N];

vector<int> bfs(){
    vector<int> distance(v,INT_MAX);
    set<pair<int,int>> q; //distance, vertex - so that it is automatically sorted by distance
    vector<int> visited(v,0);
    q.emplace(0,0);

    while(!q.empty()){
        int src = q.begin()->second;
        if(visited[src]) continue;
        visited[src] = 1;
        q.erase(q.begin());

        for(auto u : g[src]){
            int dest = u.first, wt = u.second;
            if(visited[dest]) continue;

            if(distance[dest] > distance[src] + wt){
                distance[dest] = distance[src] + wt;
                q.emplace(distance[dest],dest);
            }
        }
    }
    return distance;
}

int main(){
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int src,dest,wt;
        cin >> src >> dest >> wt;
        g[src].emplace_back(dest,wt);
        g[dest].emplace_back(src,wt);
    }

    auto shortestPaths = bfs();
    for(auto u : shortestPaths) cout << u << " "; 
}