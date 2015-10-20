#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestValue(TreeNode* root, double target)
    {
        if (!root) return INT_MAX;
        if (!(root -> left) && !(root -> right)) return root -> val;
        int left = closestValue(root -> left, target);
        int right = closestValue(root -> right, target);
        double td = abs(root -> val - target), ld = abs(left - target), rd = abs(right - target);
        if (td < ld) return td < rd ? root -> val : right;
        else return ld < rd ? left : right;
    }

    int closestValue(TreeNode* root, double target)
    {
        int a = root->val;
        auto kid = target < a ? root->left : root->right;
        if (!kid) return a;
        int b = closestValue(kid, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }

    int closestValue(TreeNode* root, double target)
    {
        int closest = root->val;
        while (root)
        {
            if (abs(closest - target) >= abs(root->val - target))
                closest = root->val;
            root = target < root->val ? root->left : root->right;
        }
        return closest;
    }
};


int main()
{

}
