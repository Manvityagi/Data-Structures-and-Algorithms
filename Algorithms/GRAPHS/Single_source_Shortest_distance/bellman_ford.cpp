#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

// Data structure to store graph edges
struct Edge
{
	int source, dest, weight;
};

// Recurive Function to print path of given vertex v from source vertex
void printPath(vector<int> const &parent, int v)
{
	if (v < 0)
		return;

	printPath(parent, parent[v]);
	cout << v << " ";
}

// Function to run Bellman Ford Algorithm from given source
void BellmanFord(vector<Edge> const &edges, int source, int N)
{
	// count number of edges present in the graph
	int E = edges.size();
	
	// distance[] and parent[] stores shortest-path (least cost/path)
	// information. Initially all vertices except source vertex have
	// a weight of infinity and a no parent

	vector<int> distance (N, INT_MAX);
	distance[source] = 0;

	vector<int> parent (N, -1);

	int u, v, w, k = N;

	// Relaxation step (run V-1 times)
	while (--k)
	{
		for (int j = 0; j < E; j++)
		{
			// edge from u to v having weight w		
			u = edges[j].source, v = edges[j].dest;
			w = edges[j].weight;
			
			// if the distance to the destination v can be
			// shortened by taking the edge u-> v
			if (distance[u] != INT_MAX && distance[u] + w < distance[v])
			{
				// update distance to the new lower value
				distance[v] = distance[u] + w;
				
				// set v's parent as u
				parent[v] = u;
			}
		}
	}

	// Run Relaxation step once more for Nth time to
	// check for negative-weight cycles
	for (int i = 0; i < E; i++)
	{
		// edge from u to v having weight w
		u = edges[i].source, v = edges[i].dest;
		w = edges[i].weight;

		// if the distance to the destination u can be
		// shortened by taking the edge u-> v		
		if (distance[u] != INT_MAX && distance[u] + w < distance[v])
		{
			cout << "Negative Weight Cycle Found!!";
			return;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << "Distance of vertex " << i << " from the source is "
			 << setw(2) << distance[i] << ". It's path is [ ";
		printPath(parent, i); cout << "]" << '\n';
	}
}

// main function
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		// (x, y, w) -> edge from x to y having weight w
		{ 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
		{ 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }
	};

	// Set maximum number of nodes in the graph
	int N = 5;

	// let source be vertex 0
	int source = 0;

	// run Bellman Ford Algorithm from given source
	BellmanFord(edges, source, N);

	return 0;
}