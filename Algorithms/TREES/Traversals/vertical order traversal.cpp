/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<int, vector<TreeNode *>> mp;
    int minhd = INT_MAX, maxhd = INT_MIN;

    void helper(TreeNode *root, int hd)
    {
        if (!root)
            return;
        minhd = min(minhd, hd);
        maxhd = max(maxhd, hd);

        mp[hd].push_back(root);
        helper(root->left, hd - 1);
        helper(root->right, hd + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        for (int i = minhd; i <= maxhd; i++)
            ans.emplace_back(mp[i]);

        return ans;
    }
};