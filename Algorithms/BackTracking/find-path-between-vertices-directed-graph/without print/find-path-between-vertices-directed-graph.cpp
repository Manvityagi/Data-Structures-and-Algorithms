#include <bits/stdc++.h>
using namespace std;

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

struct Edge
{
    int src;
    int dest;
};

//dont print the path
bool findpath(Graph g, int src, int dest, bool visited[])
{
    if (src == dest)
    {
        return true;
    }

    visited[src] = true;
    //src se jaha jaha bhi jaana possible hai , jaao, dest pe pahoch gaye to true return kar hi rahe hai, nahi to return false
    for(auto v : g.adjList[src]){
        if(!visited[v])
        findpath(g,v,dest,visited);
    }
    visited[src] = false;

    return false;
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