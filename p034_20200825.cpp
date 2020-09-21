// apply binary search twice

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.size()==0 or nums[0]>target or nums.back()<target) return {-1,-1};
        if (nums.size()==1)
        {
            if (nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        int lo = 1;
        int hi = nums.size()-1;
        if (nums[0]==target) lo = 0;
        else
        {
            while(1)
            {
                if (nums[lo]==target and nums[lo-1]<target) break;
                if (nums[lo]>target and nums[lo-1]<target) return {-1,-1};
                int mi=(lo+hi)/2;
                if (nums[mi]<target) lo = mi+1;
                else hi = mi;
            }            
        }
        if (nums.back()==target) return {lo,int(nums.size()-1)};
        if (lo==nums.size()-1 or nums[lo+1]>target) return {lo,lo};
        int loo = lo;
        hi = nums.size()-2;
        while(1)
        {
            if (nums[hi]==target and nums[hi+1]>target) return {loo,hi};
            int mi=(lo+hi+1)/2;
            if (nums[mi]<=target) lo = mi;
            else hi = mi-1;
        }            
        return {-1,-1};

    }
};