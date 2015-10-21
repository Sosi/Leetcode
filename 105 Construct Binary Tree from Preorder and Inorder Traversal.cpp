class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root=NULL;
        stack<TreeNode *> MyData;
        if(preorder.empty()) return root;
        root = new TreeNode(preorder[0]);
        MyData.push(root);
        int index = 0;
        for(int i=1; i<=preorder.size(); i++)
        {
            TreeNode *cur = MyData.top();
            if((MyData.top()->val)!=inorder[index])
            {
                cur->left = new TreeNode(preorder[i]);
                MyData.push(cur->left);
            }
            else
            {
                while(!MyData.empty() && ((MyData.top()->val)==inorder[index]))
                {
                    cur=MyData.top();
                    MyData.pop();
                    index++;
                }
                if(index<inorder.size())
                {
                    cur->right = new TreeNode(preorder[i]);
                    MyData.push(cur->right);
                }
            }
        }
        return root;
    }
};
