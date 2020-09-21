class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& t_res, int n,int k) {
        if (t_res.size()==k) {res.push_back(t_res);return;}
        int start_i=1;
        if (t_res.size()>0) start_i = t_res.back()+1;
        int end_i = n-(k-t_res.size())+1;
        for (int i=start_i;i<=end_i;i++)
        {
            t_res.push_back(i);
            helper(res,t_res,n,k);
            t_res.pop_back();
        }
        return;
        

        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> t_res;
        helper(res,t_res,n,k);
        return(res);
    }
};