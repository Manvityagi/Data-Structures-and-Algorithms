#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int indegree[N][N];
int length[N][N];
int arr[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m, n, ans;

bool valid(int a, int b)
{
    return a >= 0 && a < n && b >= 0 && b < m;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int newi = i + dx[k];
                int newj = j + dy[k];
                if(!valid(newi,newj)) continue;
                if (arr[newi][newj] == arr[i][j] + 1) indegree[newi][newj]++;
            }
        }
    }
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (indegree[i] == 0) q.emplace(i, j), length[i][j] = 1;
    
    while(q.size())
    {
         auto front = q.front();
         q.pop();
         int i = front.first, j = front.second;
         ans = max(ans,length[i][j]);
         for(int k = 0; k < 4; k++)
         {
             int newi = i + dx[k], newj = j + dy[k];
             if(!valid(newi, newj)) continue;
             if(arr[newi][newj] == arr[i][j] + 1) {
                 length[i][j]++;
                 indegree[newi][newj]--;
                 if(indegree[newi][newj] == 0) q.emplace(newi,newj);
             }
         }
    }
    cout << ans << "\n";
}
