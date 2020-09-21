class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        for (int i=0;i<nums.size();i++) s+=(i-nums[i]);
        return(s);
    }
};