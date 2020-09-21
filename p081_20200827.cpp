class Solution {
public:
    bool helper(vector<int>& nums, int target, int lo, int hi)
    {
        if (lo>hi) return(false);
        int mi = lo + (hi-lo)/2;
        if (target==nums[mi]) return(true);
        if (nums[lo]<=nums[mi] and nums[mi]<=nums[hi] and nums[lo]!=nums[hi])
        {
            if (target<nums[lo] or target>nums[hi]) return(false);
            if (target<nums[mi]) return(helper(nums,target,lo,mi-1));
            return(helper(nums,target,mi+1,hi));
        }
        if (helper(nums,target,lo,mi-1)) return(true);
        return(helper(nums,target,mi+1,hi));
    }
    bool search(vector<int>& nums, int target) {
        return(helper(nums,target,0,nums.size()-1));
    }
};