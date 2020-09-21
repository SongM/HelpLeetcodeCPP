class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return(0);
        int n=matrix[0].size();
        if (n==0) return(0);
        vector<vector<int>> dp(m,vector<int>(n,0));
        int res = 0;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (matrix[i][j]=='0') continue;
                if (i==0 or j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                res = max(res,dp[i][j]);
            }
        }
        return(res*res);
    }
};