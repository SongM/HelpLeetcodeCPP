class Solution {
public:
    int helper(vector<int>& nums, int lo, int hi)
    {
        if (lo==hi or nums[lo]<nums[hi]) return(nums[lo]);
        int mi = lo+(hi-lo)/2;
        return(min(helper(nums,lo,mi),helper(nums,mi+1,hi)));
    }
    int findMin(vector<int>& nums) {
        return(helper(nums,0,nums.size()-1));
    }
};