//ID DONT KNOW WHATS WRONG WITH IT
#include <bits/stdc++.h>
using namespace std;

bool checksum(vector<int> sumLeft)
{
    for (auto e : sumLeft)
        if (e != 0)
            return false;

    return true;
}

bool subsetsum(vector<int> sumLeft, int totalbuckets, vector<int> home, vector<int> nums, int n)
{
    if (n < 0)
        return false;

    if (checksum(sumLeft))
        return true;

    bool res = false;

    //nth item ko har bucket me baari baari daalo
    for (int i = 0; i < totalbuckets; i++)
    {
        if (sumLeft[i] - nums[n] >= 0)
        {

            //mark current elt subset
            home[n] = i + 1; //kaafi doubtful , isko to backtrack kiya hi nahi

            //add current item to ith bucket
            sumLeft[i] -= nums[n];

            //recur for remaining items
            res = subsetsum(sumLeft, totalbuckets, home, nums, n - 1);

            //backtrack
            sumLeft[i] += nums[n];
        }
    }

    return res;
}

void partition(vector<int> S, int n, int k)
{
    int n = S.size(), sum = 0;

    for (int i = 0; i < n; i++)
        sum += S[i];

    int targetsum = sum / k;

    vector<int> sumLeft(k);

    for (int i = 0; i < k; i++)
    {
        sumLeft[i] = targetsum;
    }

    vector<int> home(n);

    bool res = !(sum % k) && subsetsum(sumLeft, k, home, S, n - 1);
    if (!res)
    {
        cout << "Partition to k subsets with equal sum is not possible";
        return;
    }

    //print the k partitions
}

int main()
{
    // Input: set of integers
    vector<int> S = {7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4};

    // number of items in S
    int k = 5;
    vector<int> bucket;
    int n = S.size();

    partition(S, n, k);

    return 0;
}