class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int> > ret;

        function<void(int, int,int, vector<int>)> dfs= [&](int k, int n, int _max, vector<int> tmp)
        {
            if(k == 1 && n < _max && n>= 1)
            {
                tmp.push_back(n);
                ret.push_back(vector<int>(tmp.rbegin(), tmp.rend()));
                return;
            }
            if(_max <= 1 || n <= 0) return;
            for(int i = _max-1; i>=1; i--)
            {
                tmp.push_back(i);
                dfs(k-1, n - i, i,tmp);
                tmp.pop_back();
            }
        };
        dfs(k,n,10, {});
        return ret;
    }
};
