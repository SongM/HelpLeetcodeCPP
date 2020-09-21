class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if (n<=1) return(0);
        vector<int> dp;
        for (int i=0;i<n+1;i++) dp.push_back(i-1);
        int j;
        for (int i=0;i<n+1;i++)
        {
            j=0;   
            while(1)
            {
                if (i-j<0 or i+j>=n or s[i-j]!=s[i+j]) break;
                dp[i+j+1] = min(dp[i+j+1],dp[i-j]+1);
                j++;
            }
            j=0;
            while(1)
            {
                if (i-j<0 or i+j+1>=n or s[i-j]!=s[i+j+1]) break;
                dp[i+j+2] = min(dp[i+j+2],dp[i-j]+1);
                j++;
            }
        }
        return(dp[n]);
    }
};