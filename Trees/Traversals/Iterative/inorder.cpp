// https://leetcode.com/problems/binary-tree-inorder-traversal/

//   Definition for a binary tree node.

#include <bits/stdc++.h>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        stack<TreeNode *> st;
        vector<int> ans;
        while (true)
        {
            if (root)
            {
                st.emplace(root);
                root = root->left;
            }
            else
            {
                if (st.empty())
                    break;
                root = st.top();
                st.pop();
                ans.emplace_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};