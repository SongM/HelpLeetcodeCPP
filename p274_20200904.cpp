class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> dp(n+1);
        for (auto cit:citations) 
        {
            if (cit>=n) cit=n;
            dp[cit]++;
        }
        int h=0;
        for (int i=n;i>=0;i--)
        {
            h+=dp[i];
            if (h>=i) return(i);
        }
        return(0);
    }
};