/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:

    int maxPathSum(TreeNode* r)
    {

        int ret = INT_MIN;

        function< int(TreeNode *)> PostOrder =[&](TreeNode * root)
        {
            int l  = 0;
            int r =0;
            if(root->left != nullptr) l = PostOrder(root->left);
            if(root->right != nullptr) r = PostOrder(root->right);
            int result = root->val;
            ret = max(ret, result + l + r);
            ret = max(ret, max(result + l , max(result + r, result)));
            return max(result + l , max(result + r, result));

        };
        PostOrder(r);
        return ret;

    }
};

class Solution {
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > re) re = l + r + root->val;
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = -2147483648;
        maxToRoot(root, max);
        return max;
    }
};


int main()
{

}
