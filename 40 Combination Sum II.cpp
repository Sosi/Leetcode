#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target)
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
                if(i&&c[i]==c[i-1]&&i>a) continue;
                res.push_back(c[i]);
                dfs(i+1,b, target - c[i],res);
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
    vector<int> x = {10,1,2,7,6,1,5};
    vector<vector<int>> y = c.combinationSum(x,8);

    for(int i = 0; i< y.size(); i++)
    {
        for(auto j: y[i]) cout<<j<<" ";
        cout<<endl;
    }
}
