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
    vector<vector<int>> adjList;

    Graph(vector<Edge> &edges, int N)
    {
        adjList.resize(N);
        for (auto e : edges)
        {
            adjList[e.src].push_back(e.dest);
            adjList[e.dest].push_back(e.src);
        }
    }
};

void hamilton(Graph &G,int start,int v,vector<int> &path,vector<bool> &visited){
    if(path.size() == v){
        for(auto e : path)
            cout << e << " ";
        cout << endl;
    } 

    for(auto dest : G.adjList[start]){
        if(!visited[dest]){
            visited[dest] = true;
            path.push_back(dest);

            hamilton(G,dest,v,path,visited);

            visited[dest] = false;
            path.pop_back();
        }
    }

    

}

int main()
{
    vector<Edge> edges;
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        Edge e;
        e.src = src;
        e.dest = dest;
        edges.push_back(e);
    }
    Graph g(edges, v);

    int start = 0;
    vector<int> path = {};
    vector<bool> visited(v);
    hamilton(g,start,v,path,visited);

}