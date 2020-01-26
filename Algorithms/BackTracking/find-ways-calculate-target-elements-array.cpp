#include <bits/stdc++.h>
using namespace std;

int ways(vector<int> arr, int target, int start, int currans, vector<char> ans)
{

    if (currans == target)
    {
        // cout << currans << " " << target << endl;
        for (auto c : ans)
            cout << c << " ";
        cout << endl;
        // ans.clear();
        return 1;
    }

    if (start >= arr.size())
    {
        return 0;
    }

    //exclude curr number
    int ex = ways(arr, target, start + 1, currans, ans);

    ans.push_back('+');
    ans.push_back(arr[start]+'0');
    int incp = ways(arr, target, start + 1, currans + arr[start], ans);
    ans.pop_back();
    ans.pop_back();

    ans.push_back('-');
    ans.push_back(arr[start]+'0');
    int incn = ways(arr, target, start + 1, currans - arr[start], ans);
    ans.pop_back();
    ans.pop_back();

    return ex + incp + incn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    vector<char> ans = {};

    cout << " hello " <<  ways(arr, target, 0, 0, ans);
}