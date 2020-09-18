
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int sc;
        int fc = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            //rightmost element after which a greater elt occurs
            if (nums[i + 1] > nums[i])
            {
                fc = i;
                break;
            }
        }

        if (fc == -1)
        {
            sort(nums.begin(), nums.end());
        }
        else
        {
            //rightmost element greater than fc 
            for (sc = n - 1; sc > fc; sc--)
            {
                if (nums[sc] > nums[fc])
                {
                    break;
                }
            }
            swap(nums[fc], nums[sc]);
            sort(nums.begin() + fc + 1, nums.end());
            //  reverse(nums.begin() + fc + 1, nums.end());
        }
    }
};