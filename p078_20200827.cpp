class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int> t_res, vector<int>& nums, int i)
    {
        if (i==nums.size()) {res.push_back(t_res);return;}
        helper(res,t_res,nums,i+1);
        t_res.push_back(nums[i]);
        helper(res,t_res,nums,i+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t_res;
        helper(res,t_res,nums,0);
        return(res);
    }
};