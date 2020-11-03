#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int hole = i;
        int val = arr[hole];
        while (hole > 0 && arr[hole - 1] > val)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = val;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    insertionSort(arr);
    for (auto &i : arr)
        cout << i;
    return 0;
}