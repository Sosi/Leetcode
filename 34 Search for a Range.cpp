class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        auto itr = equal_range(nums.begin(), nums.end(), target);
        if(itr.first == itr.second)
        {
            return {-1,-1};
        }else
        return {itr.first - nums.begin(), itr.second - nums.begin() - 1};
    }
};
