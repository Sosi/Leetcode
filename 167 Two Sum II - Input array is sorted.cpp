
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret(2,-1);
        int left = 0;
        int right = numbers.size()-1;
        while(left < right)
        {
            int tmp = numbers[left]+numbers[right];
            if(tmp == target)
            {
                ret[0] = left+1;
                ret[1] = right+1;
                return ret;
            }
            else if(tmp < target)
            //make tmp larger
                left ++;
            else
            //make tmp smaller
                right --;
        }
    }
};
