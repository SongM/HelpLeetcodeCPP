class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return(0);
        int res = 1;
        vector<int> dp(n,INT_MAX);
        dp[0] = nums[0];
        int l=1;
        for (int i=1;i<n;i++)
        {
            if (nums[i]<=dp[0]) dp[0] = nums[i];
            else if (nums[i]>dp[l-1]) dp[l++] = nums[i];
            else
            {
                int lo = 0;
                int hi = l-1;
                while(lo+1<hi)
                {
                    int j = lo+(hi-lo)/2;
                    if (nums[i]>dp[j]) lo = j;
                    else hi = j;
                }
                dp[lo+1] = nums[i];
            }
                
            // for (auto ii:dp)
            //     cout<<ii<<",";
            // cout<<endl;
        }
        return(l);
        
    }
};