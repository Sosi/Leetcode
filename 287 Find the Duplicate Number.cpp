#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int l=nums.size();
        int slow =l-1;
        int fast = l-1;
        while(1)
        {
            slow=nums[slow]-1;
            fast=nums[nums[fast]-1]-1;
            if(slow == fast)
            {
                break;
            }
        }
        fast = l-1;
        while(1)
        {
            slow=nums[slow]-1;
            fast=nums[fast]-1;
            if(slow==fast)return slow+1;
        }

    }
};

int main()
{
    vector<int> v = {1,2,3,4,5};
    Solution c;
    cout<<c.findDuplicate(v)<<endl;
}
