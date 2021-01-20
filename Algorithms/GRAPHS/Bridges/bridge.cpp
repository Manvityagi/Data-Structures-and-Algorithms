#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<int> g[100];
vector<int> vis;

vector<pair<int, int>> bridges()
{
    vector<int> dis(v), low(v); //dis - discovery time, low - earliest possible node from which we can reach this node
    int current = 0;
    vector<pair<int, int>> bridges;
    function<void(int, int)> dfs = [&](int src, int par) {
        dis[src] = low[src] = ++current;
        for (auto dest : g[src])
        {
            if (dest == par)
                continue;
            if (dis[dest])
            {
                low[dest] = min(low[dest], low[src]);
            }
            else
            {
                dfs(dest, src);
                low[src] = min(low[src], low[dest]);
                if (low[dest] > low[src])
                {
                    bridges.emplace_back(src, dest);
                }
            }
        }
    };

    for (int i = 1; i <= v; i++)
        if (!dis[i])
            dfs(i, -1);

    return bridges;
}

int main()
{
    string pdfpath = "manvi";
    cout << "the Report is in Path: " + pdfpath + "saved, do you want to open it";
    cin >> v >> e;
    vis.resize(v + 1);
    for (auto i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    return 0;
}