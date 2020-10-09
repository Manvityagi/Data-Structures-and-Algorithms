#include <bits/stdc++.h>
using namespace std;
int v, e;
const int N = 100;
vector<pair<int, int>> g[N];

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

int main()
{
	cin >> v >> e;
	int source = 0; 
	for (int i = 0; i < e; i++){
		int src, dest, wt;
		cin >> src >> dest >> wt;
		Edge e(src, dest, wt);
		edges.emplace_back(e);
	}
	//INT_MAX = 2e9
	vector<int> distance(v+1,1e9); 
	distance[source] = 0; 
	for(int i = 1; i <= v-1; i++){
		for(auto a : edges){
			if(distance[a.dest] > distance[a.src] + a.wt){
				distance[a.dest] = distance[a.src] + a.wt;
			}
		}
	}

	for(auto a : edges){
		if(distance[a.dest] > distance[a.src] + a.wt){
			cout << "Negative Weight Cycle dtected";
			break;
		}
	}

	return 0;
}