// a straightforward extention of 3sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0;
        while(i+3<n)
        {
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) {i++;continue;}
            
            int j=i+1;
            while(j+2<nums.size())
            {
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if (nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) {j++;continue;}
                int left = j+1;
                int right = nums.size()-1;
                while(left<right)
                {
                    int s = nums[i]+nums[j]+nums[left]+nums[right];
                    if(s<target) left++;
                    else if (s>target) right--;
                    else
                    {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right and nums[left]==nums[left-1]) left++;
                        while(left<right and nums[right]==nums[right+1]) right--;
                    }                }
                j++;
                while(j+2<nums.size() and nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i+3<nums.size() and nums[i]==nums[i-1]) i++;
        }
        return(res);        
        
    }
};