// dynamic programming
// O(n^2) time complexity.
// there should be a better O(n) solution

class Solution {
public:
    int longestValidParentheses(string s) {
        int l=s.size();
        if (l<2) return(0);
        vector<int> dp;
        int res = 0;
        for (int i=0;i<l-1;i++) {
            if (s[i]=='(' and s[i+1]==')') 
            {
                dp.push_back(2);
                res = 2;
            }
            else dp.push_back(0);
        }
        if (res==0) return(res);
        for (int ll=4;ll<=l;ll+=2)
        {
            for (int i=0;i<=l-ll+1;i++)
            {
                if (dp[i]==0) continue;
                if (dp[i]==ll-2 and i>0 and s[i-1]=='(' and i+ll-2<l and s[i+ll-2]==')')
                {
                    dp[i-1] = ll;
                    res = ll;
                    continue;
                }
                if (i+dp[i]<l and dp[i+dp[i]]==ll-dp[i])
                {
                    dp[i]=ll;
                    res=ll;
                }
            }
            // printVector(dp);
        }
        return(res);
    }
};