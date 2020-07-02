vector<int> printCommon(Node *root1, Node *root2)
{
    vector<int> res;
    stack<Node *> s1;
    stack<Node *> s2;

    while (1)
    {
        if (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        else if (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        else if (!s1.empty() && !s2.empty())
        {
            root1 = s1.top();
            root2 = s2.top();

            if (root1->data == root2->data)
            {
                res.push_back(root1->data);
                s1.pop();
                s2.pop();
                root1 = root1->right;
                root2 = root2->right;
            }
            // move to the inorder successor
            else if (root1->data < root2->data)
            {
                // If Node of first tree is smaller, than that of
                // second tree, then its obvious that the inorder
                // successors of current Node can have same value
                // as that of the second tree Node. Thus, we pop
                // from s1
                s1.pop();
                root1 = root1->right;

                // root2 is set to NULL, because we need
                // new Nodes of tree 1
                root2 = NULL;
            }
            else if (root1->data > root2->data)
            {
                s2.pop();
                root2 = root2->right;
                root1 = NULL;
            }
        }
        else
            break;
    }
    return res;
}
