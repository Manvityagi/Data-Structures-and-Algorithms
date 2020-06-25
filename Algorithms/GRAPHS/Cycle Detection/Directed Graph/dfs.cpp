#include <bits/stdc++.h>
using namespace std;

void moveVertex(int curr, unordered_set<int> &src, unordered_set<int> &dest)
{
    if (src.find(curr) != src.end())
        src.erase(curr);
    dest.insert(curr);
}

bool dfs(vector<vector<int>> g, int curr, unordered_set<int> &white, unordered_set<int> &gray, unordered_set<int> &black)
{
    //move current to gray set from white set and then explore it.
    moveVertex(curr, white, gray);
    for (auto neighbor : g[curr])
    {
        //if neighbor has already been explored continue
        if (black.find(neighbor) != black.end())
            continue;

        //if in gray set - that means from the same parent we are visting the same neighbor twice,
        //hence there is a cycle

        if (gray.find(neighbor) != gray.end())
            return true;

        if (dfs(g, neighbor, white, gray, black))
            return true;
    }

    //move vertex from gray set to black set when done exploring.
    moveVertex(curr, gray, black);
    return false;
}

bool detectCycle(vector<vector<int>> g, int n)
{
    //whiteset - all unvisted vertices
    //grayset - vertices being visited currently
    //black set - vertices completely visited

    unordered_set<int> white, gray, black;
    for (int i = 1; i <= n; i++)
        white.insert(i);

    while (white.size())
    {
        for (int current = 1; current <= n; current++)
        {
            if (white.find(current) != white.end())
            {
                if (dfs(g, current, white, gray, black))
                    return true;
            }
        }
    }
    return false;
}