// typical dynamic programming problem.
// before coding, consider all the possible situations.
// watch out for the dummy prefix (d*c*a*b matching aab)
// notice that an empty string always matches an empty string so that dp[0][0]=1

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp;
        for (int i=0;i<=m;i++)
        {
            vector<bool> t(n+1);
            dp.push_back(t);
        }
        dp[0][0]=true;
        for (int j=1;j<n;j+=2)
        {
            if (p[j]=='*') dp[0][j+1] = 1;
            else break;
        }
        for (int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (dp[i][j]==1 and (s[i]==p[j] or p[j]=='.')) 
                {
                    dp[i+1][j+1]=1;
                    continue;
                }
                if (p[j]=='*')
                {
                    if (dp[i+1][j-1]==1 or (dp[i][j+1]==1 and (p[j-1]=='.' or s[i]==p[j-1])))
                    {
                        dp[i+1][j+1]=1;
                        continue;                        
                    }
                }
            }
        }
        return(dp[m][n]);
    }
};

