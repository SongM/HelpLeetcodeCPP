class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size()<2) return(nums);
        sort(nums.begin(),nums.end());
        vector<int> res = {};
        vector<vector<int>> dp;
        for (int i=0;i<nums.size();i++)
        {
            dp.push_back({});
            for (int j=i-1;j>=0;j--)
            {
                if (nums[i]%nums[j]==0 and dp[i].size()<dp[j].size()+1)
                    dp[i] = dp[j];
            }
            dp[i].push_back(nums[i]);
            if (dp[i].size()>res.size()) res = dp[i];
        }
        return(res);
        
    }
};