class Solution
{
public:
    int minCostII(vector<vector<int> >& costs)
    {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        vector<int> dp = costs[0];
        int minCost = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            // pair of cost - color
            pair<int int=""> min1 = make_pair(INT_MAX,-1);
            pair<int int=""> min2 = make_pair(INT_MAX,-1);
            // find the smallest two values from previous painting job
            for (int j = 0; j < k; j++)
            {
                if (dp[j] < min1.first)
                {
                    min2 = min1;
                    min1.first = dp[j];
                    min1.second = j;
                }
                else if (dp[j] < min2.first)
                {
                    min2.first = dp[j];
                    min2.second = j;
                }
            }

            for (int j = 0; j < k; j++)
            {
                if (j == min1.second)
                {
                    dp[j] = costs[i][j] + min2.first;
                }
                else
                {
                    dp[j] = costs[i][j] + min1.first;
                }
            }
        }

        for (int i = 0; i < k; i++)
        {
            minCost = min(minCost,dp[i]);
        }

        return minCost;
    }
};
