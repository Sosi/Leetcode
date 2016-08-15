// unordered_map hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> M;
        for(int i = 0; i< nums.size(); i++)
        {
            if(M.find(target - nums[i]) == M.end())
                M[nums[i]] = i;
            else
                return {M[target - nums[i]],i};
        }
        return vector<int>();
    }
};


// sort
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int> > num;
        for(int i = 0; i< nums.size(); i++)
        {
            num.push_back(make_pair(nums[i], i+1));
        }
        sort(num.begin(), num.end());

        int p = 0; int q= num.size() - 1;
        vector<int> ret;
        while(p < q)
        {
            if(num[p].first + num[q].first == target)
            {
                ret = vector<int>{num[p].second, num[q].second};
                break;
            }else if(num[p].first  + num[q].first < target) p++;
            else q--;
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
