// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
bool dfs(int G[][MAX], int v, int src, int color, vector<int> &col, vector<int> &visited){
    visited[src] = 1;
    col[src] = color;
    for(int i = 0; i < v; i++){
       if(G[src][i] == 1){
           int nbr = i; 
            if(visited[nbr] && col[nbr] == color) return false;
            if(visited[nbr]) continue;
            if(!dfs(G,v,nbr,!color,col,visited)) return false; 
       }
    }
    
  return true;
}

bool isBipartite(int G[][MAX],int V)
{
    vector<int> visited(V,0), col(V,-1); 
    for(int i = 0; i < V; i++){
        if(!visited[i])
            if(!dfs(G,V,i,0,col,visited)) return false;
    }
     return true; 
}