#include <bits/stdc++.h>

using namespace std;

// worst case
class Solution1
{
public:
    int getMoneyAmount(int n)
    {
        vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
        for(int interval = 1; interval < n; interval ++)
        {
            for(int i = 1; i< n && i+interval <=n; i++)
            {
                int j = i+interval;
                dp[i][j] = INT_MAX;
                for(int k = i; k<=j; k++)
                {
                    dp[i][j] = min(dp[i][j], k+ max(i<k-1?dp[i][k-1]:0, k+1<j? dp[k+1][j]: 0));
                }
            }
        }
        return dp[1][n];
    }
};

// expected case
class Solution2
{
public:
    int getMoneyAmount(int n)
    {
        vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
        record.resize(n+1, vector<int>(n+1, 0));
        for(int interval = 1; interval < n; interval ++)
        {
            for(int i = 1; i< n && i+interval <=n; i++)
            {
                int j = i+interval;
                dp[i][j] = INT_MAX;
                for(int k = i; k<=j; k++)
                {
                    int tmp =(j-i)*k+ (i<k-1?dp[i][k-1]:0) +  (k+1<j? dp[k+1][j]: 0);
                    dp[i][j] = dp[i][j] < tmp? dp[i][j]: (record[i][j] = k,tmp);
                }
            }
        }
        return dp[1][n];
    }
    vector< vector<int> > record;
};

