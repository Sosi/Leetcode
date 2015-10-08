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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root==NULL)
            return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* node= nodeStack.top();
            result.push_back(node->val);
            nodeStack.pop();
            if(node->left)
                nodeStack.push(node->left);
            if(node->right)
                nodeStack.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root==NULL)
            return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* node= nodeStack.top();
            result.push_back(node->val);
            nodeStack.pop();
            if(node->right)
                nodeStack.push(node->right);
            if(node->left)
                nodeStack.push(node->left);
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        TreeNode * cur = root;
        while(!nodeStack.empty() || cur != nullptr)
        {
            if(cur != nullptr)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }else
            {
                cur = nodeStack.top();
                result.push_back(cur->val);
                nodeStack.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};


int main()
{
    Solution c;

    vector<TreeNode> t(7, TreeNode(0));
    for(int i = 1; i<= 7 ; i++)
    {
        t[i-1] = TreeNode(i);
    }
    for(int i = 1; i<= 3; i++)
    {
        t[i-1].left = &(t[(i<<1) - 1]);
        t[i-1].right = &(t[(i<<1)]);
    }

//    for(int i = 1;i< )

    vector<int> ret  = c.inorderTraversal(&(t[0]));

    for(auto itm : ret) cout<<itm<<endl;


}
