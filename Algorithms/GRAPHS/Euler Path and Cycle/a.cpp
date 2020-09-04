/* Euler Cycle
    1. All vertices with non-zero degree are connected.  
    2. All vertices have even degree. 
*/ 


/*Euler Path
    1. All vertices with non-zero degree are connected. 
    2. 0 or 2 vertices have odd degree and all other vertices have even degree.  
*/


bool Graph::isConnected() {
    bool found = 0; 
    bool visited[V]; 
    for(int i = 0; i < V; i++) visited[i] = 0; 
    
    int i;
    for(i = 0; i < V; i++)
        if(adj[i].size() != 0) break; 
    
    if(i == V) return 1;
    
    DFSUtil(i,visited);
    
    //check if everything is visited
    for(int i = 0; i < V; i++)
        if(!visited[i] && adj[i].size() > 1) return 0; 
    
    return 1; 
}

int Graph::isEulerian(){
        if(!isConnected()) return 0; 
        
        int odd = 0; 
        for(int i = 0; i < V; i++)
            if(adj[i].size() & 1) odd++;
        
        if(odd == 0) return 2; //cycle 
        if(odd == 2) return 1; //path
        return 0; //none 

}