class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size()==0) return {};
        vector<string> res;
        int start_i = 0;
        for (int i=1;i<nums.size();i++)
        {
            if (long(nums[i])-long(nums[start_i])==i-start_i) continue;
            if (i==start_i+1) res.push_back(to_string(nums[start_i]));
            else res.push_back(to_string(nums[start_i]) + "->" + to_string(nums[i-1]));
            start_i = i;
        }
        if (nums.size()==start_i+1) res.push_back(to_string(nums[start_i]));
        else res.push_back(to_string(nums[start_i]) + "->" + to_string(nums[nums.size()-1]));
        return(res);
    }
};