class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int t_res = 0;
        for (int i=0;i<nums.size();i++)
        {
            t_res+=nums[i];
            if (res<t_res) res = t_res;
            if (t_res<0) {t_res=0;continue;}
        }
        return(res);
    }
};