class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0 or nums.size()<2 or nums.size()==k) return;
        int count=0;
        
        int i=0;
        int t = nums[i];
        int tt;
        int start_i = i;
        for (int j=0;j<nums.size();j++)
        {
            i = (i+k)%nums.size();
            tt = nums[i];
            nums[i] = t;
            t = tt;
            if (i==start_i) {i++;start_i=i;t = nums[i];}
        }
        return;
    }
};