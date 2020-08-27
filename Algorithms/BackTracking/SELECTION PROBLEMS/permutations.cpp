#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n;
void permute1(vector<int> &curr, vector<int> &visited){
        if(curr.size() == n){
            for(auto &i:curr) cout << i << " ";
            cout << "\n";
        }

        for(int j = 0; j < n; j++){
            if(visited[j]) continue;
            curr.push_back(arr[j]);
            visited[j] = 1;
            permute1(curr,visited);
            curr.pop_back();
            visited[j] = 0;
        }
}

void permute2(vector<int> &curr){
        if(curr.size() == n){
            for(auto &i:curr) cout << i << " ";
            cout << "\n";
        }

        for(int j = 0; j < n; j++){
            if(find(curr.begin(),curr.end(),arr[j]) != curr.end()) continue;
            curr.push_back(arr[j]);
            permute2(curr);
            curr.pop_back();
        }
}

int main()
{
    cin >> n;
    arr.resize(n);
    for (auto &a : arr) cin >> a;
    vector<int> curr = {};
    vector<int> visited(n);
    permute1(curr, visited);
    curr = {};
    permute2(curr);
}