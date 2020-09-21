class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0;
        int j=0;
        int ss = 0;
        int res = nums.size()+1;
        while(j<nums.size())
        {
            if (ss<s) ss+=nums[j++];
            else
            {
                res = min(res,j-i);
                ss-=nums[i++];
            }
            if (res==1) break;
        }
        while(ss>=s)
        {
            res = min(res,j-i);
            ss-=nums[i++];
        }
        return(res%(nums.size()+1));
    }
};