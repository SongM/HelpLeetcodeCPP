// watch out for the boundary conditions.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return(0);
        int i=1;
        int j=1;
        while(i<nums.size())
        {
            if (nums[i]!=nums[i-1])
                nums[j++]=nums[i++];
            else
                nums[j]=nums[i++];
        }
        return(j);
    }
};