int numDistinct(string S, string T) {
    int m = T.length();
    int n = S.length();
    if (m > n) return 0;    // impossible for subsequence
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int k = 0; k <= n; k++) dp[0][k] = 1;    // initialization

    for(int i = 1; i<= m; i++)
    {
        for(int j = i; j<=n; j++)
        {
            dp[i][j] = dp[i][j-1] + ((T[i-1] == S[j-1])?dp[i-1][j-1]:0);
        }
    }
    return dp[m][n];
}
