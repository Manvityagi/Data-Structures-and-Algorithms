#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src,dest;
};

class Graph {
    public:
        vector<vector<int>> adjList;
    //constructor
    Graph(vector<edge> const &edges, int N){
        adjList.resize(N);
        for(auto &edge : edges){
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

void dfs(Graph const &graph, int v, vector<int> arrival, vector<int> dept, vector<bool> &discovered, int &time)
{
    arrival[v] = time++;
    discovered[v] = true;
    for(auto u : graph.adjList[v]) {
        if(!discovered[u]){
            dfs(graph,u,arrival,dept,discovered,time);
        }
    }
    dept[v] = time++;
}




//  Edit distance
//  Longest palindrome sequence memoized
//  Tabulation v
//  Longest palindrome substring
//  Min palindromic cut
//  Matrix chain multiplication
//  Egg drop
//  Maxm sum no adjacent element
//  Count of n length binary string in which there are no adjacent 0
//  Fractional knapsack
//  Climb down
//  Count maze path
//  Min cost path
//  Gold mine
//  Min jumps
//  Plargest increasing subsequence
//  Rod cutting
//  Target sum subset
//  Coin change permutation
//  Coin change combination
//  Unbounded knapsack
//  Zero one knapsack
//  Lcs
