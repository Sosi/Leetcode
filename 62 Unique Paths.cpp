class Solution
{
public:
    long long fab(int x, int y)
    {
        long long ret = 1;
        for (int i = x; i >= y && i > 0; --i)
        {
            ret *=i;
        }
        return ret;
    }

    int uniquePaths(int m, int n)
    {
        if (0 == m || 0 == n)
        {
            return 0;
        }

        int max = std::max(m, n) - 1;
        int min = std::min(m, n) - 1;

        int ret = int(fab(max + min, max + 1) / fab(min, 1));

        return ret;
    }
};


class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};
