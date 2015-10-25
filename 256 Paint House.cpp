class Solution
{
public:
    int minCost(vector<vector<int>>& costs)
    {
        int n = costs.size();
        if (n == 0) return 0;
        int dp0 = costs[0][0];
        int dp1 = costs[0][1];
        int dp2 = costs[0][2];

        for (int i = 1; i < n; i++)
        {
            int t0 = dp0, t1 = dp1, t2 = dp2;
            dp0 = costs[i][0] + min(t1,t2);
            dp1 = costs[i][1] + min(t2,t0);
            dp2 = costs[i][2] + min(t1,t0);
        }

        return min(min(dp0,dp1),dp2);
    }
};
