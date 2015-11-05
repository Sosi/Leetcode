class Solution {
public:
bool is_palin(string s)
{
    int i = 0, j = s.size() - 1;
    while(i < j)
    {
        if(s[i] != s[j] ) return false;
        i++; j--;
    }
    return true;
}

void dfs(vector<vector<string> > & con, vector<string> &tmp,  string s)
{
    if(s == "") con.push_back(tmp);

    for(int i = 0; i< s.size(); i++)
    {
        if(is_palin(s.substr(0, i+1)))
        {
            tmp.push_back( s.substr(0, i+1));
            dfs(con,tmp, s.substr(i+1, s.size()-i -1));
            tmp.pop_back();
        }
    }
    return ;
}
vector<vector<string> > partition(string s)
{
    vector<vector<string> > ret;
    vector<string> tmp;
    dfs( ret, tmp, s);
    return ret;
}
};
