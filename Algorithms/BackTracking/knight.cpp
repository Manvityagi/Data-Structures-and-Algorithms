
// https://www.youtube.com/watch?v=pwlxQeHchFQ&t=614s
#include <bits/stdc++.h>
using namespace std;
#define N 5
int row[] = {2, 1, -1, -2, -2, -1, 1, 2, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1, 1};

bool isValid(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void knight(int x, int y, vector<vector<int>> ans,int moves)
{
    ans[x][y] = moves;
    if (moves >= N*N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << ans[i][j];
        }
        return;
    }

    for(int t = 0; t < 8; t++){
        int newx = row[t] + x;
        int newy = col[t] + y;
        if(isValid(newx,newy) && !(ans[newx][newy])){
            knight(newx,newy,ans,moves+1);
        }
    }

    ans[x][y] = 0;
}

int main()
{
    int visited[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            visited[i][j] = 0;
    }

    vector<vector<int>> ans(N, vector<int>(N));
    knight(0, 0, ans,1);
}