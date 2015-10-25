public class Solution {
    public int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        if (n == 1)
            return k;
        int same_count = k;
        int differ_count = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            int temp = differ_count;
            differ_count = differ_count * (k - 1) + same_count * (k - 1);
            same_count = temp;
        }
        return same_count + differ_count;
    }
}
