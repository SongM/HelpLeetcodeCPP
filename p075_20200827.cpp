class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0;
        int c=nums.size()-1;
        int i=0;
        while(i<=c)
        {
            if (nums[i]==0)
            {
                nums[i++]=1;
                nums[a++]=0;
                continue;
            }
            if (nums[i]==1)
            {
                i++;
                continue;
            }
            nums[i] = nums[c];
            nums[c--] = 2;
        }
        return;
    }
};