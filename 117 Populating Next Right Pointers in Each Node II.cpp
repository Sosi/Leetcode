/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        TreeLinkNode *head = NULL;  //head of the next level
        TreeLinkNode *prev = NULL; // current node  the next level
        TreeLinkNode *cur = root;  //  current node  the current level

        while(cur != NULL)
        {
            // iterate in the current level;
            while(cur != NULL)
            {
                if(cur->left != NULL)
                {
                    if(prev != NULL)
                        prev->next = cur->left;
                    else head = cur->left;
                    prev = cur->left;
                }
                if(cur->right != NULL)
                {
                    if(prev != NULL)
                        prev->next = cur->right;
                    else head = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }
    }
};

int main()
{

}
