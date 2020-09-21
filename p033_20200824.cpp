//variation of binary search.

class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int j)
    {
        if (i==j) return(nums[i]==target?i:-1);
        if (i==j-1)
        {
            if (nums[i]==target) return(i);
            if (nums[j]==target) return(j);
            return(-1);
        }
        int mi = (i+j)/2;
        if (nums[mi]==target) return(mi);
        if (nums[i]<nums[mi] and nums[mi]<nums[j])
        {
            if (nums[mi]>target) return(helper(nums,target,i,mi-1));
            return(helper(nums,target,mi+1,j));
        }
        int res = helper(nums,target,i,mi-1);
        if (res==-1) return(helper(nums,target,mi+1,j));
        return(res);
    }
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) return(-1);
        return(helper(nums,target,0,nums.size()-1));
    }
};