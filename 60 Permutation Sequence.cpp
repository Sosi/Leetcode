
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string ans = "";
        int i, j, t, sum, jie;
        jie = 1;
        for (i = 1; i <= n; i++)
        {
            jie = i * jie;
            ans += to_string(i);
        }
        for (i = 0; i < n; i++)
        {
            jie /= n - i;
            for (sum = 0, j = 1; j <= n; j++)
            {
                if (sum + jie >= k) break;
                sum += jie;
                swap(ans[i], ans[i + j]);
            }
            k -= sum;
        }
        return ans;
    }
};

