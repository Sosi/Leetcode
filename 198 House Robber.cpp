class Solution {
public:
    int rob(vector<int> nums) {
        if(nums.size() == 0) return 0;
        vector<vector<int> >  dp = vector<vector<int> >(nums.size(), {0,0});

        for(int i = 0; i< nums.size(); i++)
        {
            if(i == 0)
            {
                dp[i][1] = nums[0];
                continue;
            }
            dp[i][0] += max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] += dp[i-1][0] + nums[i];
        }
        return max(dp[nums.size()-1][0], dp[nums.size() -1][1]);

    }
};
