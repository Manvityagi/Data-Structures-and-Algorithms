#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
	int src, dest;
};

class Graph
{
public:
	vector<vector<int>> adjList;

	Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);

		for (auto &edge : edges)
			adjList[edge.src].push_back(edge.dest);
	}
};

void dfs(Graph &G, int N, int u, vector<bool> &visited, vector<int> &departure, int& time)
{

	visited[u] = true;
	time++;

	for (auto v : G.adjList[u])
	{
		if (!visited[v])
			dfs(G, N, v, visited, departure, time);
	}

	departure[time] = u;
	time++;
}

void doTopologicalSort(Graph &G, int N)
{
	vector<int> departure(2 * N, -1);
	int time = 0;
	vector<bool> visited(N, false);

	for (int i = 0; i < N; i++)
		if (!visited[i])
			dfs(G, N, i, visited, departure, time);

	for (int i = 2 * N - 1; i >= 0; i--)
	{
		if (departure[i] != -1)
		{
			cout << departure[i] << " ";
		}
	}
}

int main()
{
	vector<Edge> edges =
		{
			{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4}, {5, 1}, {7, 0}, {7, 1}};

	int N = 8;

	Graph graph(edges, N);

	doTopologicalSort(graph, N);

	return 0;
}