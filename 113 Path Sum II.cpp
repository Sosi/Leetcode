/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector<vector<int> > ret;
        if(root == nullptr) return ret;
        function<void(TreeNode * , vector<int>, int)> dfs = [&](TreeNode* root, vector<int> path, int _sum)
        {

            path.push_back(root->val);
            _sum += root->val;

            if(root->left == NULL && root->right == NULL)
            {
                if(_sum == sum)
                    ret.push_back(path);
                return;
            }
            if(root->left) dfs(root->left, path, _sum);
            if(root->right) dfs(root->right, path, _sum);
        };
        dfs(root, {}, 0);
        return ret;
    }
};
