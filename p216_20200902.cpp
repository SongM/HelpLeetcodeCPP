class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& t_res, int k, int n)
    {
        if (k==1) 
        {
            if (n<=t_res.back() or n>9) return;
            t_res.push_back(n);
            res.push_back(t_res);
            t_res.pop_back();
            return;
        }
        for (int i=t_res.back()+1;i<=min(10-k,n/k);i++)
        {
            t_res.push_back(i);
            helper(res,t_res,k-1,n-i);
            t_res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> t_res;
        for (int i=1;i<=min(10-k,n/k);i++)
        {
            t_res.push_back(i);
            helper(res,t_res,k-1,n-i);
            t_res.pop_back();            
        }
        return(res);
    }
};