class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = nums[0];
        for(int i = 1; i< nums.size(); i++)
        {
            if(far < i) return false;
            if(nums[i] + i > far) far = nums[i] + i;
        }
        return true;
    }
};
