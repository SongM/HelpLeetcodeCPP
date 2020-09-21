class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return(0);
        int res = 1;
        vector<int> dp(n,1);
        
        for (int i=n-2;i>=0;i--)
        {
            for (int j=i+1;j<n;j++)
            {
                if (nums[j]>nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res,dp[i]);
        }
        return(res);
    }
};