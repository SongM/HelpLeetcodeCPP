// backtracking problem

class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& nums,int l)
    {
        if (l==1) 
        {
            res.push_back(nums);
            return;
        }
        helper(res,nums,l-1);
        for (int i=0;i<l-1;i++)
        {
            swap(nums[i],nums[l-1]);
            helper(res,nums,l-1);
            swap(nums[i],nums[l-1]);
        }
        return;
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,nums.size());
        return(res);
    }
};