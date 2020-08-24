// use sorted array to solve twoSum with O(n)
// need to skip duplicated items 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3) return(res);        
        sort(nums.begin(),nums.end());
        
        int i=0;
        while(i+2<nums.size())
        {
            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                int s = nums[i]+nums[left]+nums[right];
                if (s<0) left++;
                else if(s>0) right--;
                else
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right and nums[left]==nums[left-1]) left++;
                    while(left<right and nums[right]==nums[right+1]) right--;
                }
            }
            i++;
            while(i+2<nums.size() and nums[i]==nums[i-1])
                i++;
        }
        return(res);
    }
};