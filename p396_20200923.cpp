class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n=A.size();
        if (n<2) return(0);
        if (n==2) return(max(A[0],A[1]));
        int s = 0;
        int res = 0;
        for (int i=0;i<n;i++)
        {
            s+=A[i];
            res +=i*A[i];
        }
        int t_res = res;
        for (int i=n-1;i>=1;i--)
        {
            t_res = t_res - n*A[i] + s;
            res = max(t_res,res);
        }
        return(res);
    }
};