// https://leetcode.com/problems/search-in-rotated-sorted-array

/* APPROACH
1) everytime check if targe == nums[mid], if so, we find it.

2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid]) 
  and if so, go to step 3), otherwise, the second half is in order,   go to step 4)

3) check if target in the range of [left, mid-1] 
(i.e. nums[left]<=target < nums[mid]), if so, 
do search in the first half, i.e. right = mid-1;
otherwise, search in the second half left = mid+1;

4)  check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), if so, 
do search in the second half, i.e. left = mid+1; 
otherwise search in the first half right = mid-1;

Credits: Leetcode Discuss
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &A, int t)
    {
        if (A.empty())
            return false;

        int l = 0, r = A.size() - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (A[m] == t)
                return true;
            if (A[l] < A[m])
            {
                if (A[l] <= t && t < A[m])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else if (A[m] < A[r])
            {
                if (A[m] < t && t <= A[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            else
            {
                if (A[l] == A[m])
                    l++;
                if (A[m] == A[r])
                    r--;
            }
        }

        return A[l] == t ? true : false;
    }
};