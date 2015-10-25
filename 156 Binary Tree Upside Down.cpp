TreeNode *UpsideDown2(TreeNode *root)
{
    if (!root -> left && !root -> right) return root;
    TreeNode *parent = NULL, *parentRight = NULL, *p = root;
    while(p)
    {
        TreeNode *left = p -> left;
        p -> left = parentRight;
        parentRight = p -> right;
        p -> right = parent;
        parent = p;
        p = left;
    }
    return parent;
}

