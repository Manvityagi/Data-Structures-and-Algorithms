const int N = 10001;
vector<int> visited(N);

bool dfs(vector<int> g[], int src, int parent){

    visited[src] = 1;  
    for(auto dest : g[src]){
        if(visited[dest] && dest != parent) return true;
        if(visited[dest]) continue;
        if(dfs(g,dest,src)) return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int v)
{
    fill(visited.begin(),visited.end(),0);
    for(int i = 0; i < v; i++)
        if(!visited[i]){
            bool cycle = dfs(g,i,-1);
            if(cycle) return true;
        } 
    return false;
   
}