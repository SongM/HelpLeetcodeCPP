// variation of p039

void printVector(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for (int i=0; i < a.size(); i++)
 	cout << a[i] << ',';
    cout<<endl;
}


class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &t_res, vector<int>& cands, vector<int>& counts, int i, int target)
    {
        if (i==cands.size()-1)
        {
            if (target%cands[i]==0)
            {
                int k=target/cands[i];
                if (k<=counts[i])
                {
                    for (int j=0;j<k;j++) t_res.push_back(cands[i]);
                    res.push_back(t_res);
                    for (int j=0;j<k;j++) t_res.pop_back();
                }
            }
            return;
        }
        int k=target/cands[i];
        if (k>counts[i]) k=counts[i];
        for (int j=0;j<=k;j++)
        {
            helper(res, t_res, cands, counts, i+1, target);        
            t_res.push_back(cands[i]);
            target-=cands[i];
        }
        for (int j=0;j<=k;j++)
        {
            t_res.pop_back();
            target+=cands[i];
        }
        
        
        return;
    }    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size()==0) return(res);
        sort(candidates.begin(), candidates.end(), greater<int>());
        int prev=candidates[0]+1;
        vector<int> cands;
        vector<int> counts;
        for (auto n:candidates)
        {
            if (n==prev) counts.back()++;
            else
            {
                cands.push_back(n);
                counts.push_back(1);
                prev=n;
            }
        }
        vector<int> t_res;
        helper(res,t_res,cands, counts,0,target);
        return(res);    
    }
};