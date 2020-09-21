class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return(0);
        if (nums.size()==1) return(nums[0]);
        int without = 0;
        int with = 0;
        for (int i=0;i<nums.size()-1;i++)
        {
            int t=without;
            without = max(with,without);
            with = t+nums[i];
        }
        int res = max(with,without);
        with = 0;
        without = 0;
        for (int i=1;i<nums.size();i++)
        {
            int t=without;
            without = max(with,without);
            with = t+nums[i];
        }
        return(max(max(res,with),without));
        
    }
};