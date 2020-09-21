class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m+n!=s3.size()) return(false);
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][0] = 1;
        for (int i=-1;i<m;i++)
        {
            for (int j=-1;j<n;j++)
            {
                if ((j>=0 and dp[i+1][j]==1 and s2[j]==s3[i+j+1]) or (i>=0 and dp[i][j+1]==1 and s1[i]==s3[i+j+1]))
                    dp[i+1][j+1]=1;
            }
        }
        return(dp[m][n]==1);
    }
};