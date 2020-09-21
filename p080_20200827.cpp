class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<3) return(nums.size());
        int l=2;
        for (int i=2;i<nums.size();i++)
        {
            if (nums[i]!=nums[i-2]) l++;
            else if (nums[l]==nums[i] and nums[l]!=nums[l-2]) l++;
            nums[l-1] = nums[i];
        }
        return(l);
    }
};