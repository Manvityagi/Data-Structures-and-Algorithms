#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> &subset, vector<int> &arr, int i){
    if(i == arr.size()){
        for(int j: subset)printf("%d ",j);
        printf("\n");
        return;
    }
    dfs(subset,arr,i+1);
    subset.emplace_back(arr[i]);
    dfs(subset,arr,i+1);
    subset.pop_back();
}

void dfs(vector<int> &subset, vector<int> &arr, int i)
{
    if (i == arr.size()){
        for (auto j : subset)
            cout << j << " ";
        cout << "\n";
        return;
    }
    subset.emplace_back(arr[i]);
    dfs(subset, arr, i + 1);
    subset.pop_back();
    dfs(subset, arr, i + 1);
}

int main(){
    vector<int> arr;
    for (auto &a : arr)
        cin >> a;
    vector<int> subset = {};
    dfs(subset,arr,0);
}