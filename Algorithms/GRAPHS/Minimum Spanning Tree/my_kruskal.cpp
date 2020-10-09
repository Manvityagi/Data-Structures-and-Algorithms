#include<bits/stdc++.h> 
using namespace std; 
vector<int> parent; 
struct Edge{
    int src; 
    int dest; 
    int wt;
    Edge(int src, int dest, int wt){
        this->src = src; 
        this->dest = dest;
        this->wt = wt;
    }
};
vector<Edge> edges; 

bool comp(const Edge &a, const Edge &b){
    return a.wt < b.wt; 
}

int find_parent(int v){ //constant - max 5,6 steps 
    if(v == parent[v]) return; 
    return parent[v] = find_parent(parent[v]); 
}

void union_set(int u, int v){
    u = find_parent(u); 
    v = find_parent(v); 
    if(u != v) parent[u] = v; 
}

int main(){
    int v,e;
    cin >> v >> e; 
    parent.resize(v+1);
    iota(parent.begin(),parent.end(),0);

    for(int i = 0; i < e; i++){
        int src,dest,wt;
        cin >> src >> dest >> wt;
        Edge e(src,dest,wt);
        edges.emplace_back(e);  
    }
    sort(edges.begin(),edges.end(),comp); //ElogE 
    vector<Edge> MST; 
    long long ans = 0; 
    for(auto a : edges){
        if(find_parent(a.src) != find_parent(a.dest)) {
            MST.emplace_back(a);
            ans += a.wt; 
            union_set(a.src,a.dest);
        }
    } 
    cout << ans;
    return 0; 
}