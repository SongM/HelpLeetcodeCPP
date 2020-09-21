// just tricky.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int num = nums[i];            
            while(num>0 and num<=n)
            {
                int t = nums[num-1];
                nums[num-1] = -n;
                num = t;
            }
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=-n) return(i+1);
        }
        return(n+1);
        
    }
};