const int CN = 26;

class TrieNode
{
public:
    // Initialize your data structure here.

    TrieNode * child[CN];
    int cnt;    // counts the number of the same prefix string
    bool is_word; // wheather this is a word.

    TrieNode(int _cnt = 0, bool _is_word = false)
    {
        for(int i= 0; i< CN; i++) child[i] = nullptr;
        cnt = _cnt;
        is_word = _is_word;
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        if(s.empty()) return;
        TrieNode *p = root;
        for(int i = 0; i< s.size(); i++)
        {
            if(p->child[s[i] - 'a'] == nullptr)
                p->child[s[i] - 'a'] = new TrieNode();
            p = p->child[s[i] - 'a'];
            p->cnt++;
        }
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i< s.size() && p != nullptr ; i++)
            p = p->child[s[i] - 'a'];
        return p!= nullptr && p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i< s.size() && p != nullptr ; i++)
            p = p->child[s[i] - 'a'];
        return p!= nullptr;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
