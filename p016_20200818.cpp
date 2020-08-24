//standard two pointer solution

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int res = nums[0]+nums[1]+nums[2];
        while(i+2<nums.size())
        {
            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                int s = nums[i]+nums[left]+nums[right];
                if (abs(s-target)<abs(res-target)) res = s;
                if (s==target) return(target);
                else if(s<target) left++;
                else right--;
            }
            i++;
        }
        return(res);
    }
};