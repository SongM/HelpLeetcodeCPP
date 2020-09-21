class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss=1;
        int i =0;
        int res = 0;
        while(miss<=n)
        {
            if (i<nums.size() and nums[i]<=miss)
            {
                miss+=nums[i];
                i++;
            }
            else
            {
                miss+=miss;
                res++;
            }
        }
        return(res);
        
    }
};