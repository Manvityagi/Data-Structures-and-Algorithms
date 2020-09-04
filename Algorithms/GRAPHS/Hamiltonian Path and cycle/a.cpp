 
void hamiltonianCycle(int N, vector<vector<int> > &graph, unordered_set<int> &visited, int src, string psf, int osrc) {
    	 if(visited.size() == N-1){
    	     cout << psf; 
    	     bool cycle = false;
    	     for(auto nbr : graph[src]){
    	         if(nbr == osrc){
    	             cycle = true;
    	             break;
    	         }
    	     }
    	     if(cycle) cout << "*";
    	     else cout << ".";
    	 }
    	 
    	 visited.insert(src);
    	 for(auto nbr : graph[src]){
    	     if(visited.find(nbr) == visited.end()){
    	         hamiltonianCycle(N,graph,visited,nbr,psf + to_string(nbr),osrc);
    	     }
    	 }
    	 visited.erase(src);
 }
 