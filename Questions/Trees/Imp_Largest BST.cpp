// https://practice.geeksforgeeks.org/problems/largest-bst/1/
struct info
{
    int size;
    int mx;
    int mn;
    bool isBST;
};

info helper(Node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, true};

    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, true};

    info l = helper(root->left);
    info r = helper(root->right);

    info res;

    if (l.isBST && r.isBST && l.mx < root->data && r.mn > root->data)
    {
        res.isBST = 1;
        res.size = 1 + l.size + r.size;
        res.mx = max(root->data, r.mx);
        res.mn = min(root->data, l.mn);
    }
    else
    {
        res.isBST = 0;
        res.size = max(l.size, r.size);
    }
    return res;
}

int largestBst(Node *root)
{
    if (!root)
        return true;

    return helper(root).size;
}