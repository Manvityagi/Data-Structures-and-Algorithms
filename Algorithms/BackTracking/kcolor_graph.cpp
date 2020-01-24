#include <bits/stdc++.h>
using namespace std;
// data structure to store graph edges
struct Edge
{
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:
    // An array of vectors to represent adjacency list
    vector<vector<int>> adj;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to N elements of type vector<int>
        adj.resize(N);

        // add edges to the undirected graph
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
    }
};

// string array to store colors (10-colorable graph)
string COLORS[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
                   "PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};

bool isValid(Graph const &graph, int clr, int vertex, vector<int> &color)
{
    for (auto v : graph.adj[vertex])
    {
        if (color[v] == clr)
            return false;
    }

    return true;
}

void kColorable(Graph const &graph, vector<int> &color, int k, int v, int N)
{

    if (v == N)
    {
       for (int v = 0; v < N; v++)
			cout << setw(8) << left << COLORS[color[v]];
		cout << endl;

        return;
    }

    //color vertex v with all avaialble colors
    for (int c = 1; c <= k; c++)
    {
        if (isValid(graph, c, v, color))
        {
            color[v] = c;

            kColorable(graph, color, k, v + 1, N);

            color[v] = 0;
        }
    }
}

int main()
{
    vector<Edge> edges = {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}};

    // Number of vertices in the graph
    int N = 6;

    // create a graph from edges
    Graph g(edges, N);

    int k = 3;

    vector<int> color(N, 0);

    // print all k-colorable configurations of the graph
    kColorable(g, color, k, 0, N);
}