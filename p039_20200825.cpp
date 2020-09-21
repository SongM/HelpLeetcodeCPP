//typical backtracking

void printVector(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for (int i=0; i < a.size(); i++)
 	cout << a[i] << ',';
    cout<<endl;
}


class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &t_res, vector<int>& candidates, int i, int target)
    {
        // cout<<i<<","<<target<<endl;
        // printVector(t_res);
        if (i==candidates.size()-1)
        {
            if (target%candidates[i]==0)
            {
                int k=target/candidates[i];
                for (int j=0;j<k;j++) t_res.push_back(candidates[i]);
                res.push_back(t_res);
                for (int j=0;j<k;j++) t_res.pop_back();
            }
            return;
        }
        int k=target/candidates[i];
        for (int j=0;j<=k;j++)
        {
            helper(res, t_res, candidates, i+1, target);        
            t_res.push_back(candidates[i]);
            target-=candidates[i];
        }
        for (int j=0;j<=k;j++)
        {
            t_res.pop_back();
            target+=candidates[i];
        }
        
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> res;
        vector<int> t_res;
        helper(res,t_res,candidates,0,target);
        return(res);
    }
};