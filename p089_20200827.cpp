class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res={0};
        for (int i=0;i<n;i++)
        {
            vector<int> t_res=res;
            reverse(t_res.begin(),t_res.end());
            for (int j=0;j<t_res.size();j++) t_res[j] +=res.size();
            res.insert(res.end(),t_res.begin(),t_res.end());
        }
        return(res);
    }
};