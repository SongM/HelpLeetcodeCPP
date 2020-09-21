

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size()==1) return {nums};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for (int i=0;i<nums.size();i++)
        {
            if (i>0 and nums[i]==nums[i-1]) continue;
            vector<int> t_nums = nums;
            t_nums.erase(t_nums.begin()+i);
            vector<vector<int>> tt_res = permuteUnique(t_nums);
            for (auto t:tt_res)
            {
                t.push_back(nums[i]);
                res.push_back(t);
            }
        }
        return(res);    
    }
};