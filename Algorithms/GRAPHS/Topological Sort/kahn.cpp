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

    vector<int> indegree;

    Graph(vector<Edge> const &edges, int N)
    {
        adjList.resize(N);

        vector<int> temp(N, 0);
        indegree = temp;

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);

            indegree[edge.dest]++;
        }
    }
};

bool doTopologicalSort(Graph const &graph, vector<int> &L, int N)
{
	vector<int> indegree = graph.indegree;

	// Set of all nodes with no incoming edges
	vector<int> S;
	for (int i = 0; i < N; i++) {
		if (!indegree[i]) {
			S.push_back(i);
		}
	}

	while (!S.empty())
	{
		// remove a node n from S
		int n = S.back();
		S.pop_back();

		// add n to tail of L
		L.push_back(n);

		for (int m : graph.adjList[n])
		{
			// remove edge from n to m from the graph
			indegree[m] -= 1;

			// if m has no other incoming edges then
			// insert m into S
			if (!indegree[m]) {
				S.push_back(m);
			}
		}
	}

	// if graph has edges then graph has at least one cycle
	for (int i = 0; i < N; i++) {
		if (indegree[i]) {
			return false;
		}
	}

	return true;
}

int main()
{
    vector<Edge> edges =
        {
            {0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4}, {5, 1}, {7, 0}, {7, 1}};

    int N = 8;

    Graph graph(edges, N);

    // Empty list that will contain the sorted elements
    vector<int> L;

    if (doTopologicalSort(graph, L, N))
    {
        for (int i : L)
            cout << i << " ";
    }
    else
    {
        cout << "Graph has at least one cycle. "
                "Topological sorting is not possible";
    }

    return 0;
}