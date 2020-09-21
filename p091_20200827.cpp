class Solution {
public:
    int numDecodings(string s) {
        if (s.size()==0 or s[0]=='0') return(0);
        if (s.size()==1) return(1);
        vector<int> dp={1};
        if (s[1]=='0') 
        {
            if (s[0]=='0' or s[0]>'2') return(0);
            dp.push_back(1);
        }
        else if (s[0]>'2') dp.push_back(1);
        else
        {
            if (s[0]=='2' and s[1]>'6') dp.push_back(1);
            else dp.push_back(2);
        }
        for (int i=2;i<s.size();i++)
        {
            if (s[i]=='0')
            {
                if (s[i-1]=='1' or s[i-1]=='2')
                {
                    dp.push_back(dp[i-2]);
                    continue;
                }
                else return(0);
            }
            dp.push_back(dp[i-1]);
            if (s[i-1]=='1' or (s[i-1]=='2' and s[i]<='6')) dp[i]+=dp[i-2];
        }
        return(dp.back());
        
    }
};