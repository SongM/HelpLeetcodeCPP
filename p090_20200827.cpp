class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& t_res, vector<pair<int,int>>& v, int i)
    {
        if (i==v.size()) {res.push_back(t_res);return;}
        for (int k=0;k<=v[i].second;k++)
        {
            helper(res,t_res,v,i+1);
            t_res.push_back(v[i].first);
        }
        for (int k=0;k<=v[i].second;k++) t_res.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto n:nums)
        {
            if (m.find(n)==m.end()) m[n]=1;
            else m[n]++;
        }
        vector<pair<int,int>> v;
        for (auto it:m) v.push_back({it.first,it.second});
        vector<vector<int>> res;
        vector<int> t_res;
        helper(res,t_res,v,0);
        return(res);
    }
};