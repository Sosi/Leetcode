int threeSumSmaller(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int sz = nums.size(), ret = 0;
    for(int i=0; i<=sz-3; ++i)
    {
        int l = i+1, r = sz-1;
        while(l<r)
        {
            int sum = nums[i]+nums[l]+nums[r];
            if(sum>=target)
            {
                r--;
            }
            else
            {
                ret += (r-l);
                l++;
            }
        }
    }
    return ret;
}
