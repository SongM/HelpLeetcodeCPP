class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        vector<uint> dp(target+1,0);
        dp[0]=1;
        
        for (int i=1;i<=target;i++)
        {
            // dp.push_back(0);
            for (int x:nums)
            {
                // if (i-x<0) break;
                if (i-x>=0)
                dp[i]+=dp[i-x];
            }
        }
        return(dp[target]);
        
        
    }
    };