class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int before = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            if(before >= 0) before += nums[i];
            ret = max(ret, before);
            if(before < 0) before = 0;
        }
        return ret;
    }
};
