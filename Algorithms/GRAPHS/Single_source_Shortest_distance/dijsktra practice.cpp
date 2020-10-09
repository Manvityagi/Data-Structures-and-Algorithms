#include<bits/stdc++.h> 
using namespace std; 
int v,e,src; 
vector<pair<int,int>> g[1000];

void dijkstra(){
    set<pair<int,int>> q; //distance, vertex  
    vector<int> distance(v+1); 
    vector<int> visited(v+1); 

    distance[src] = 0;
    q.emplace(0,src);
    
    while(!q.empty()){
        auto rem = q.begin();
        int currV = rem->second, currDis = rem->first; 
        if(visited[currV]) continue; 
        q.erase(q.begin()); 

        visited[currV] = 1;

        for(auto nbr : g[currV]){
            int nbrV = nbr.second, nbrDis = nbr.first; 
            if(visited[nbrV]) continue;
            if(distance[nbrV] > distance[currV] + nbrDis){
                distance[nbrV] = distance[currV] + nbrDis;
                q.emplace(distance[nbrV],nbrV); 
            }
        }

    }

}

int main(){
    cin >> v >> e >> src; 
    dijkstra();
}
