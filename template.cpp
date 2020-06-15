#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009

void bfs(int n, int s, vector<vector<int>> &g, vector<int> &lev){
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(s);
    lev[s] = 0;
    vis[s] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int &v: g[u]){
            if(!vis[v]){
                lev[v] = lev[u]+1;
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
        }
    }
    return 0;
}
