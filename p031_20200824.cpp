// finding increasing moment
class Solution {
public:
    void swap(vector<int>& nums,int i,int j)
    {
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
        return;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<2) return;
        int changing_point_i = 0;
        for (int i=nums.size()-1;i>0;i--)
        {
            if (nums[i]>nums[i-1])
            {
                changing_point_i = i;
                break;
            }
        }
        if (changing_point_i>0)
        {
            for (int i=nums.size()-1;i>=changing_point_i;i--)
            {
                if (nums[i]>nums[changing_point_i-1])
                {
                    swap(nums,i,changing_point_i-1);
                    break;
                }
            }
        }
        for (int j=0;j<(nums.size()-changing_point_i)/2;j++) swap(nums,changing_point_i+j,nums.size()-j-1);        
        return;
    }
};