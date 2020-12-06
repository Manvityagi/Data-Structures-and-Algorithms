#include <bits/stdc++.h>
using namespace std;

/*
1. Find rightmost element smaller than its next element  - fc
2. Find smallest number after fc which is greater than fc 
3. swap fc & sc 
4. sort after original index of fc 

*/

void next_permute(vector<int> &nums){
    int n = nums.size();
    int fc = -1;
    for (int i = n - 2; i >= 0; i--){
        if (nums[i] < nums[i + 1]){
            fc = i;
            break;
        }
    }
    if (fc == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    int sc = fc + 1;
    for (int i = fc + 1; i < n; i++){
        if (nums[i] > nums[fc] && nums[i] < nums[sc])
            sc = i;
    }
    swap(nums[fc], nums[sc]);
    sort(nums.begin() + fc + 1, nums.end());
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums)
        cin >> i;
    next_permute(nums);
    for (auto &i : nums)
        cout << i;
    return 0;
}