/* Program to find LCA of n1 and n2 using one DFS on 
the Tree */
#include <bits/stdc++.h>
using namespace std;

// Maximum number of nodes is 100000 and nodes are
// numbered from 1 to 100000
#define MAXN 100001

vector<int> tree[MAXN];
int path[3][MAXN]; // storing root to node path

// storing the path from root to node
//1, 0, 1, 1, a, flag
//1, 0, 2, 1, b, flag
void dfs(int cur, int prev, int pathNumber, int ptr,
         int node, bool &flag)
{
    for (int i = 0; i < tree[cur].size(); i++)
    {
        if (tree[cur][i] != prev and !flag)
        {
            // pushing current node into the path
            path[pathNumber][ptr] = tree[cur][i];
            if (tree[cur][i] == node)
            {
                // node found
                flag = true;

                // terminating the path
                path[pathNumber][ptr + 1] = -1;
                return;
            }
            dfs(tree[cur][i], cur, pathNumber, ptr + 1,
                node, flag);
        }
    }
}

// This Function compares the path from root to 'a' & root
// to 'b' and returns LCA of a and b. Time Complexity : O(n)
int LCA(int a, int b)
{
    // trivial case
    if (a == b)
        return a;

    // setting root to be first element in path
    path[1][0] = path[2][0] = 1;

    // calculating path from root to a
    bool flag = false;
    dfs(1, 0, 1, 1, a, flag);

    // calculating path from root to b
    flag = false;
    dfs(1, 0, 2, 1, b, flag);

    // runs till path 1 & path 2 mathches
    int i = 0;
    while (path[1][i] == path[2][i])
        i++;

    // returns the last matching node in the paths
    return path[1][i - 1];
}

void addEdge(int a, int b)
{
    tree[a].push_back(b);
    tree[b].push_back(a);
}

// Driver code
int main()
{
    int n = 8; // Number of nodes
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(3, 7);
    addEdge(3, 8);

    cout << "LCA(4, 7) = " << LCA(4, 7) << endl;
    cout << "LCA(4, 6) = " << LCA(4, 6) << endl;
    return 0;
}
