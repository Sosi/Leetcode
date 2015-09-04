class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int len= 0;
        ListNode * x = head;
        while(x) len++,x = x->next;
        x = head;
        function<TreeNode *(int)> dfs = [&](int n)
        {
            TreeNode * node = nullptr;
            if(n == 0) return node;
            node = new TreeNode(0);
            node->left = dfs(n/2);
            node->val = x->val;
            x = x->next;
            node->right = dfs(n - n/2 - 1);
            return node;
        };
        return dfs(len);
    }
};
