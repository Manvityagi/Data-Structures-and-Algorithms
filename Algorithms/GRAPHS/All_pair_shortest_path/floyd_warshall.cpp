#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

// Number of vertices in the adjMatrix
#define N 4

// Recursive Function to print path of given 
// vertex u from source vertex v
void printPath(int path[][N], int v, int u)
{
	if (path[v][u] == v)
		return;

	printPath(path, v, path[v][u]);
	cout << path[v][u] << " ";
}

// Function to print the shortest cost with path 
// information between all pairs of vertices
void printSolution(int cost[N][N], int path[N][N])
{
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			if (cost[v][u] == INT_MAX)
				cout << setw(5) << "inf";
			else
				cout << setw(5) << cost[v][u];
		}
		cout << endl;
	}

	cout << endl;
	for (int v = 0; v < N; v++) 
	{
		for (int u = 0; u < N; u++) 
		{
			if (u != v && path[v][u] != -1) 
			{
				cout << "Shortest Path from vertex " << v << 
					 " to vertex " << u << " is (" << v << " ";
				printPath(path, v, u);
				cout << u << ")" << endl;
			}
		}
	}
}

// Function to run Floyd-Warshell algorithm
void FloydWarshell(int adjMatrix[][N])
{
	// cost[] and parent[] stores shortest-path 
	// (shortest-cost/shortest route) information
	int cost[N][N], path[N][N];

	// initialize cost[] and parent[]
	for (int v = 0; v < N; v++) 
	{
		for (int u = 0; u < N; u++) 
		{
			// initally cost would be same as weight 
			// of the edge
			cost[v][u] = adjMatrix[v][u];

			if (v == u)
				path[v][u] = 0;
			else if (cost[v][u] != INT_MAX)
				path[v][u] = v;
			else
				path[v][u] = -1;
		}
	}
	
	// run Floyd-Warshell
	for (int k = 0; k < N; k++) 
	{
		for (int v = 0; v < N; v++) 
		{
			for (int u = 0; u < N; u++) 
			{
				// If vertex k is on the shortest path from v to u,
				// then update the value of cost[v][u], path[v][u]

				if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
					&& cost[v][k] + cost[k][u] < cost[v][u]) 
				{
					cost[v][u] = cost[v][k] + cost[k][u];
					path[v][u] = path[k][u];
				}
			}

			// if diagonal elements become negative, the
			// graph contains a negative weight cycle
			if (cost[v][v] < 0) 
			{
				cout << "Negative Weight Cycle Found!!";
				return;
			}
		}
	}

	// Print the shortest path between all pairs of vertices
	printSolution(cost, path);
}

// main function
int main()
{
	// given adjacency representation of matrix
	int adjMatrix[N][N] =
	{ 
		{	   0, INT_MAX,	  -2, INT_MAX },
		{	   4,	   0,	   3, INT_MAX },
		{ INT_MAX, INT_MAX,	   0,	   2 },
		{ INT_MAX,	  -1, INT_MAX,	   0 } 
	};

	// Run Floyd Warshell algorithm
	FloydWarshell(adjMatrix);

	return 0;
}