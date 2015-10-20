#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target)
    {
        sort(c.begin(), c.end());
        vector<vector<int> > ret;
        vector<int> res;
        function<void (int,int,int,vector<int> &)> dfs = [&](int a, int b, int target, vector<int> & res )
        {
//        cout<<a<<" ---> "<<b<<endl;
            if(target == 0) ret.push_back(res);
            if(target < c[a]) return;
            for(int i = a; i<b; i++)
            {
                res.push_back(c[i]);
                dfs(i,b, target - c[i],res);
                res.pop_back();
            }
        };
        dfs(0,c.size(),target, res);
        return ret;
    }
};


int main()
{
    Solution c;
    vector<int> x = {1,2,3,6,7};
    vector<vector<int>> y = c.combinationSum(x,7);

    for(int i = 0; i< y.size(); i++)
    {
        for(auto j: y[i]) cout<<j<<" ";
        cout<<endl;
    }
}
