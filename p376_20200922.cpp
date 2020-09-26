class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2) return(nums.size());
        int n = nums.size();
        int i = 1;
        while(i<n and nums[i]==nums[i-1]) i++;
        if (i==n) return(1);
        bool b_increase = nums[i]>nums[i-1];
        int prev = nums[i-1];
        int res = 2;
        i++;
        while (i<n)
        {
            if ((b_increase==true and nums[i]<nums[i-1]) or (b_increase==false and nums[i]>nums[i-1]))
                {b_increase = !b_increase; res++;}
            i++;
        }
        return(res);
            
    }
};