class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int idx = 0;
        function<TreeNode *(int)> dfs = [&](int n) {
            TreeNode * node = nullptr;
            if(n == 0) return node;
            node = new TreeNode(0);
            node->left = dfs(n/2);
            node->val = nums[idx++];
            node->right = dfs(n - n/2 - 1);
            return node;
        };
        return dfs(nums.size());
    }
};
