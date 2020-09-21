class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if (n==0) return(true);
        // if (wordDict.size()==0) return(false);
        vector<bool> dp(n+1);
        dp[0]=true;
        unordered_set<string> m(wordDict.begin(),wordDict.end());
        unordered_set<int> length_bank;
        for (auto word:wordDict) length_bank.insert(word.size());
        for (int i=0;i<n;i++)
        {
            for (auto l:length_bank)
            {
                if (i-l+1>=0 and dp[i-l+1]==true and m.find(s.substr(i-l+1,l))!=m.end()) 
                    {dp[i+1]=true;break;}
            }
        }
        return(dp[n]);
        
    }
};