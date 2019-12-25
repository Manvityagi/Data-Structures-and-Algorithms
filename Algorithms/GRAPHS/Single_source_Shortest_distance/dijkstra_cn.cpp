#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Data structure to store graph edges
struct Edge {
	int dest, weight;
};

// data structure to store heap nodes
struct Node {
	int vertex, weight;
};

struct compare
{
    bool operator()(const Node &a, const Node &b){
        return a.weight > b.weight;
    }
};

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  vector<vector<Edge>> adjList(V, vector<Edge>(E));
  vector<bool> visited(V,0);
  priority_queue<Node,vector<Node>, compare> minpq;
  vector<int> dist(V,INT_MAX);
    for(int i = 0; i < V; i++)
    {
        int ei,ej,wi;
        cin >> ei >> ej >> wi;
        
        adjList[ei].push_back({ej,wi});   
        adjList[ej].push_back({ei,wi});   

    }
    dist[0] = 0;
    visited[0] = 1;
    minpq.push({0,0});
    
    while(!minpq.empty()) {
        Node node = minpq.top();
        minpq.pop();
        
       // get vertex number
		int u = node.vertex;

		// do for each neighbor v of u
		for (auto i : adjList[u])
		{
			int v = i.dest;
			int weight = i.weight;

			// Relaxation step
			if (!visited[v] && (dist[u] + weight) < dist[v])
			{
				dist[v] = dist[u] + weight;
				minpq.push({v, dist[v]});
			}
		}
        
        visited[u] = 1;      
    }
    
    for(int i = 0; i < dist.size(); i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    
  return 0;
}
