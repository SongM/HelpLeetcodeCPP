class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size()==0 or nums[0]>=target) return(0);
        if (nums.back()<target) return(nums.size());
        int lo=0;
        int hi = nums.size()-1;
        while(hi>lo+1)
        {
            int mi=lo + (hi-lo)/2;
            if (nums[mi]==target) return(mi);
            if (nums[mi]<target) lo = mi;
            else hi = mi;
        }
        return(lo+1);
    }
};