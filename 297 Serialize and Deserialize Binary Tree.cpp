class Codec
{
public:

    string serialize(TreeNode* root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out)
    {
        if (root)
        {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        string str;
        while (!q.empty())
        {
            if (q.front() == nullptr)
            {
                str = str + "#,";
            }
            else
            {
                q.push(q.front()->left);
                q.push(q.front()->right);
                str = str + to_string(q.front()->val) + ",";
            }
            q.pop();
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        string::iterator first = data.begin();
        while (first != data.end())
        {
            TreeNode** pp = q.front();
            if (*first == '#')
            {
                // *pp = nullptr;
                advance(first, 2);
            }
            else
            {
                string::iterator last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
