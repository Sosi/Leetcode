public class Solution
{
    public void wiggleSort(int[] nums)
    {
        if (nums == null || nums.length <= 0)
            return;
        for (int i = 1; i < nums.length; i++)
        {
            if (i % 2 == 1)
            {
                if (nums[i-1] > nums[i])
                    swap(nums, i, i-1);
            }
            else
            {
                if (nums[i] > nums[i-1])
                    swap(nums, i, i-1);
            }
        }
    }


    private void swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
