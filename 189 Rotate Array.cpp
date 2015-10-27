class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        for (; k = k%n; n -= k, nums += k)
        {
            // Swap the last k elements with the first k elements.
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[i], nums[n - k + i]);
            }
        }
    }
};
