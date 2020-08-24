// typical backtracking problem.
// use t_res to store current string
// use i to represent the number of left bracket needed
// use j to represent the number of right bracket needed

        -> ((( -> ((()))
( -> (( -> (() -> (()( -> (()())
               -> (()) -> (())( ->(())()
  -> () -> ()( -> ()(( -> ()(())
               -> ()() -> ()()( -> ()()()


class Solution {
public:
    void helper(vector<string> &res, string t_res, int i, int j)
    {
        // cout<<t_res<<","<<i<<","<<j<<endl;
        if (i==0)
        {
            t_res+=string(j,')');
            res.push_back(t_res);
            return;
        }
        helper(res,t_res+"(",i-1,j+1);
        if (j>0) helper(res,t_res+")",i,j-1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,"",n,0);
        return(res);
    }
};