const int N = 10001;
vector<int> visited(N);

bool dfs(vector<int> g[], int src, int parent){
	visited[src] = 1;        
    for(auto dest : g[src]){
        if(visited[dest] == 2) continue;
        if(visited[dest] == 1) return true;
        if(dfs(g,dest,src)) return true;
    }
    visited[src] = 2;
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