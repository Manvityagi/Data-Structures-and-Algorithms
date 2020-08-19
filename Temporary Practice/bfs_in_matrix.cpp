#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> g[N];
//isme visited bhi check karna padega , jo tune nhi kiya hua hai

int main() {
    int t;
    int dx[] ={ 1, -1, 0, 0 }, dy[]={ 0, 0, 1, -1 };
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> arr[i][j];

        function<bool(int, int)> valid = [&](int i, int j)->bool {
            return i >= 0 && i < n && j >= 0 && j < n;
        };

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector<vector<int>> dis(n, vector<int>(n, 0));
        while (!q.empty())
        {
            int i, j;
            tie(i, j) = q.front();
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dx[dir], y = j + dy[dir];
                if (!valid(i, j)) continue;

                dis[x][y] = dis[i][j]+1;
                q.emplace(x, y);
            }
        }
    }
    return 0;
}