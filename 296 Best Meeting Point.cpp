class Solution
{
public:
    int minTotalDistance(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> ii, jj;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    ii.push_back(i);
                    jj.push_back(j);
                }
            }
        }
        sort(jj.begin(), jj.end());
        int c = ii.size(), s = 0, io = ii[c/2], jo = jj[c/2];
        for (int i : ii) s += abs(i - io);
        for (int j : jj) s += abs(j - jo);
        return s;
    }
};
