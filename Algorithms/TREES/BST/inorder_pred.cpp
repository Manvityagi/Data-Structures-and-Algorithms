class Solution
{
public:
    //recursion
    int recursion(int l, int r)
    {
        if (l >= r)
            return 1;
        int count = 0;
        for (int root = l; root <= r; root++)
        {
            count += recursion(l, root - 1) * recursion(root + 1, r);
        }
        return count;
    }

    vector<vector<int, int>> memo(n + 1, vector<int>(n + 1, -1));

    //memo
    int memo(n)
    {
        if ()
    }

    int numTrees(int n)
    {
        // return recursion(1,n);
        return memo(n);
    }
};