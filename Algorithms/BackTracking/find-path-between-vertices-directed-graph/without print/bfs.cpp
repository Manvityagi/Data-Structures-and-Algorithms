#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src;
    int dest;
};
class Graph
{
public:
    int V;
    int E;
    vector<vector<int>> adjList;

    Graph(vector<Edge> edges, int V)
    {
        adjList.resize(V);
        for (auto e : edges)
        {
            adjList[e.src].push_back(e.dest);
        }
    }
};



//dont print the path
bool findpath(Graph g, int src, int dest, bool visited[])
{
    
}

int main()
{
    int E, V;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++)
    {
        int src;
        int dest;
        Edge e;
        cin >> src >> dest;
        e.src = src;
        e.dest = dest;
        edges.push_back(e);
    }

    Graph g(edges, V);

    int src, dest;
    cin >> src >> dest;
    bool visited[V]{};
    cout << findpath(g, src, dest, visited);
}
