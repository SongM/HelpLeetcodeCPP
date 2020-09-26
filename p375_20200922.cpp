class Solution {
public:
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1));
        
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n-1;i++)
            dp[i][i+1] = i;
        // for (int i=1;i<=n-1;i++)
        //     dp[i][i+2] = i+1;
        for (int l=3;l<=n;l++)
        {
            for (int i=1;i<=n-l+1;i++)
            {
                int j=i+l-1;
                dp[i][j] = 40000;
                for (int k=i+(j-i)/2;k<j;k++)
                    dp[i][j] = min(dp[i][j],k + max(dp[i][k-1],dp[k+1][j]));
            }
        }
        return(dp[1][n]);
    }
};