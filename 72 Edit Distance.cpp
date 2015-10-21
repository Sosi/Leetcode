class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m==0 || n==0 )return max(m,n);
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)  dp[i][0] = i;
        for(int i=0; i<=n; i++)  dp[0][i] = i;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j];
                else dp[i+1][j+1] = min( min(dp[i+1][j]+1, dp[i][j+1]+1), dp[i][j]+1);
            }
        }
        return dp[m][n];
    }
};
