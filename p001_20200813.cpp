//using dict for search achieves O(1)
//in total O(n) time complexity


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for (int i=0;i<nums.size();i++)
        {
            if (m.find(target-nums[i])!=m.end())
                return {m[target-nums[i]],i};
            m[nums[i]]=i;
        }
        return {};
    }
};
