
/* APPROACH

(1) Parent Pointer 
(2) O(1) space - Iterative approach
    Case 1 : If right subtree if present - ans is the smallest (leftmost) node in right subtree
    Case 2 : Right subtree is not null - ans is the most recemt ancestor of which the current node is a left child
*/

/*--------------------------------APPROACH-1---------------------------------------------------*/

Node *parent = NULL;
Node *ans = NULL;
void helper(Node *root, Node *x)
{
    if (!root)
        return;
    helper(root->left, x);
    if (parent == x)
        ans = root;
    parent = root;
    helper(root->right, x);
}
Node *inOrderSuccessor(Node *root, Node *x)
{
    ans = NULL;
    parent = NULL;
    helper(root, x);
    return ans;
}

/*--------------------------------APPROACH-2---------------------------------------------------*/

Node *inOrderSuccessor(Node *root, Node *x)
{
    if (!root || !x)
        return NULL;
    Node *parent = NULL;
    while (root)
    {
        if (x->data >= root->data)
            root = root->right;
        else
        {
            parent = root;
            root = root->left;
        }
    }
    return parent;
}