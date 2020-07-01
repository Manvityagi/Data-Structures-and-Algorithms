vector<int> Solution::postorderTraversal(TreeNode *root)
{

    if (!root)
        return {};
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->val);

        if (root->left)
            st.push(root->left);
        if (root->right)
            st.push(root->right);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
