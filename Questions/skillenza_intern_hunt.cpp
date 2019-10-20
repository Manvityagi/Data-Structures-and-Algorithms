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
#define INF LONG_MAX
#define db(x, y) cout << x << " " << y << endl;
#define LD long double
#define PR pair<LD, LL>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class node
{
public:
    int max;
    int ways;
    node()
    {
        max = 0;
        ways = 0;
    }
};

bool valid(int i, int j, int n)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

node helper(vector<vector<char>> arr)
{
    int n = arr.size();
    vector<vector<int>> points(n, vector<int>(n, 0));
    vector<vector<int>> ways(n, vector<int>(n, 0));

    //last row
    ways[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[i][j] != 'x' && arr[i][j] != 's' && arr[i][j] != 'e')
            {
                // int way1 = valid(i+1,j+1,n) ? ways[i+1][j+1] : 0;
                // int way2 = valid(i,j+1,n) ? ways[i][j+1] : 0;
                // int way3 = valid(i+1,j,n) ? ways[i+1][j] : 0;
                // ways[i][j] = way1 + way2 + way3;

                int point1 = valid(i + 1, j + 1, n) ? points[i + 1][j + 1] : 0;
                int point2 = valid(i, j + 1, n) ? points[i][j + 1] : 0;
                int point3 = valid(i + 1, j, n) ? points[i + 1][j] : 0;
                int maxp = max(point1, max(point2, point3));
                points[i][j] = arr[i][j] - '0' + maxp;

                if (maxp == point1)
                {
                    ways[i][j] += ways[i + 1][j + 1];

                    if (maxp == point2 && maxp == point3)
                    {
                        if (valid(i + 1, j, n) && valid(i, j + 1, n))
                            ways[i][j] = ways[i + 1][j] + ways[i][j + 1];
                    }
                    else if (maxp == point2)
                    {
                        if (valid(i, j + 1, n))
                            ways[i][j] += ways[i][j + 1];
                    }
                    else if (maxp == point3)
                    {
                        if (valid(i + 1, j, n))
                            ways[i][j] += ways[i + 1][j];
                    }
                }

                else

                    if (maxp == point2)
                {
                    ways[i][j] += ways[i][j + 1];

                    if (maxp == point1 && maxp == point3)
                    {
                        if (valid(i + 1, j, n) && valid(i + 1, j + 1, n))
                            ways[i][j] = ways[i + 1][j] + ways[i + 1][j + 1];
                    }
                    else if (maxp == point1)
                    {
                        if (valid(i + 1, j + 1, n))
                            ways[i][j] += ways[i + 1][j + 1];
                    }
                    else if (maxp == point3)
                    {
                        if (valid(i + 1, j, n))
                            ways[i][j] += ways[i + 1][j];
                    }
                }

                else if (maxp == point3)
                {
                    ways[i][j] += ways[i + 1][j];

                    if (maxp == point2 && maxp == point1)
                    {
                        if (valid(i + 1, j, n) && valid(i, j + 1, n))
                            ways[i][j] = ways[i + 1][j + 1] + ways[i][j + 1];
                    }
                    else if (maxp == point2)
                    {
                        if (valid(i, j + 1, n))
                            ways[i][j] += ways[i][j + 1];
                    }
                    else if (maxp == point1)
                    {
                        if (valid(i + 1, j + 1, n))
                            ways[i][j] += ways[i + 1][j + 1];
                    }
                }
            }
        }
    }

    node ans;
    ans.max = max(points[0][1], max(points[1][1], points[1][0]));
    if (ans.max == points[0][1])
        ans.ways = ways[0][1];
    else if (ans.max == points[1][0])
        ans.ways = ways[1][0];
    else
        ans.ways = ways[1][1];

    return ans;
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
        vector<vector<char>> arr(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        node ans = helper(arr);
        cout << ans.max << " " << ans.ways << endl;
    }
    return 0;
}
