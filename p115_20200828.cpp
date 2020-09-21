class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        if (m<n) return(0);
        vector<vector<long>> dp(m,vector<long>(n));
        int count=0;
        for (int i=0;i<m;i++)
        {
            if (s[i]==t[0]) count++;
            dp[i][0]=count;
        }
        for (int j=1;j<n;j++)
        {
            for (int i=j;i<m;i++)
            {
                if (s[i]==t[j]) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return(dp[m-1][n-1]);
    }
};