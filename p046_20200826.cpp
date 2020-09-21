class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size()==1) return {nums};
        vector<vector<int>> res;
        for (int i=0;i<nums.size();i++)
        {
            vector<int> t_nums = nums;
            t_nums.erase(t_nums.begin()+i);
            vector<vector<int>> tt_res = permute(t_nums);
            for (auto t:tt_res)
            {
                t.push_back(nums[i]);
                res.push_back(t);
            }
        }
        return(res);
    }
};