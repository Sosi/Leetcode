class Solution
{
public:
    void recoverTree(TreeNode* root)
    {
        pre = first = second = NULL;
        inorder(root);
        if (first)
        {
            int temp = first -> val;
            first -> val = second -> val;
            second -> val = temp;
        }
    }
private:
    TreeNode *first, *second, *pre;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root -> left);
        if (pre && pre -> val > root -> val)
        {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        inorder(root -> right);
    }
};
