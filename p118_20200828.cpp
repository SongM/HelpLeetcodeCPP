class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows==0) return(res);
        res.push_back({1});
        if (numRows==1) return(res);
        for (int i=2;i<=numRows;i++)
        {
            vector<int> t_res={1};
            for (int j=0;j<i-2;j++) t_res.push_back(res.back()[j]+res.back()[j+1]);
            t_res.push_back(1);
            res.push_back(t_res);
        }
        return(res);
    }
};