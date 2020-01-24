#include <bits/stdc++.h>
using namespace std;
int M = 10, N = 10;
int maxpath = INT_MAX;

int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};

bool isValid(int r, int c)
{
    return r >= 0 && r < M && c >= 0 && c < N;
}

int mat[10][10] =
    {
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
};

vector<vector<bool>> visited(M, vector<bool>(N, false));

void mazepath(int destx, int desty, int currx, int curry, int currlen)
{
    visited[currx][curry] = true;
    if (currx == destx && curry == desty)
    {
        //update ans if needed
        if (currlen < maxpath)
        {
            maxpath = currlen;
        }
        visited[currx][curry] = false;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newx = currx + row[i];
        int newy = curry + col[i];

        if (mat[newx][newy] == 1 && isValid(newx, newy) && !(visited[newx][newy]))
        {
            mazepath(destx, desty, newx, newy, currlen + 1);
            visited[newx][newy] = false;
        }
    }
}

int main()
{
    int srcx, srcy;
    int destx, desty;
    cin >> srcx >> srcy >> destx >> desty;

    mazepath(destx, desty, srcx, srcy, 0);

    cout << maxpath;
}