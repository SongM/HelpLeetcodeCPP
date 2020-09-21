class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> ddp(n+1);
        for (auto word:wordDict) 
        {
            int len = word.size();
            if (len>n or ddp[len]==true) continue;
            if (s.substr(0,len)==word) ddp[len]=true;
        }
        for (int i=0;i<=n;i++)
        {
            if (ddp[i]==false) continue;
            for (auto word:wordDict) 
            {
                int len = word.size();
                if (i+len>n or ddp[i+len]==true or s.substr(i,len)!=word) continue;
                ddp[i+len]=true;
            }
        }
        if (ddp[n]==false) return {};

        vector<vector<string>> dp(n+1);
        for (auto word:wordDict) 
        {
            int len = word.size();
            if (len>n) continue;
            if (s.substr(0,len)==word) dp[len].push_back(word);
        }
        for (int i=0;i<=n;i++)
        {
            if (dp[i].size()==0) continue;
            for (auto word:wordDict) 
            {
                int len = word.size();
                if (i+len>n or s.substr(i,len)!=word) continue;
                for (auto t_res:dp[i])
                    dp[i+len].push_back(t_res+" "+word);
            }
        }
        return(dp[n]);
        

        
    
    }
};