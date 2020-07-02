// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        TreeNode *cur1 = root1, *cur2 = root2;

        while (cur1 || cur2 || !s1.empty() || !s2.empty())
        {
            while (cur1)
            {
                s1.push(cur1);
                cur1 = cur1->left;
            }
            while (cur2)
            {
                s2.push(cur2);
                cur2 = cur2->left;
            }

            if (s2.empty() || (!s1.empty() && s1.top()->val < s2.top()->val))
            {
                cur1 = s1.top();
                s1.pop();
                ans.emplace_back(cur1->val);
                cur1 = cur1->right;
            }
            else
            {
                cur2 = s2.top();
                s2.pop();
                ans.emplace_back(cur2->val);
                cur2 = cur2->right;
            }
        }
        return ans;
    }
};