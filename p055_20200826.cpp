class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i=0;i<nums.size();i++)
        {
            if (i>maxPos) return(false);
            if (i+nums[i]>maxPos) 
            {
                maxPos = i+nums[i];
                if (maxPos>=nums.size()-1) break;
            }
        }
        return(true);
    }
};