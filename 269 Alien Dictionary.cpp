class Solution
{
public:
    string alienOrder(vector<string>& words)
    {
        unordered_set<char> nodes;
        unordered_map<char, unordered_set<char>> links;
        int i = 0, cont = 1;
        while(cont)
        {
            cont = 0;
            string prefixOld = "";
            char prevC = '.';
            for(string w:words)
            {
                if(w.size()>i+1) cont = 1;
                if(i<w.size())
                {
                    char c = w[i];
                    nodes.insert(c);
                    string prefix = w.substr(0, i);
                    if(prefixOld!=prefix) prefixOld = prefix;
                    else if(prevC!='.' && prevC!=c) links[prevC].insert(c);
                    prevC = c;
                }
            }
            i++;
        }

        stack<char> stk;
        unordered_set<char> visited;
        string ret;
        for(auto node:nodes)
        {
            unordered_set<char> path;
            if(visited.count(node)==0)
                if(!dfs(node, visited, stk, links, path)) return ret;
        }

        while(!stk.empty())
        {
            ret += stk.top();
            stk.pop();
        }

        return ret;
    }
    bool dfs(char node, unordered_set<char> &visited, stack<char> &stk, unordered_map<char, unordered_set<char>> &links, unordered_set<char> path)
    {
        visited.insert(node);
        path.insert(node);
        for(auto nb:links[node])
        {
            if(path.count(nb)==1) return false;
            if(visited.count(nb)==0)
                if(!dfs(nb, visited, stk, links, path)) return false;
        }
        stk.push(node);
        return true;
    }
};
