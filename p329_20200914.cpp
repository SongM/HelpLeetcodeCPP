class Solution {
public:
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int m, int n)
    {
        if (dp[i][j]==0)
        {
            int t_res = 1;
            if (i-1>=0 and matrix[i-1][j]>matrix[i][j]) t_res = max(t_res,1+helper(matrix,dp,i-1,j,m,n));
            if (i+1<m and matrix[i+1][j]>matrix[i][j]) t_res = max(t_res,1+helper(matrix,dp,i+1,j,m,n));
            if (j-1>=0 and matrix[i][j-1]>matrix[i][j]) t_res = max(t_res,1+helper(matrix,dp,i,j-1,m,n));
            if (j+1<n and matrix[i][j+1]>matrix[i][j]) t_res = max(t_res,1+helper(matrix,dp,i,j+1,m,n));
            dp[i][j] = t_res;
        }
        return(dp[i][j]);
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=0;
        int m=matrix.size();
        if (m==0) return(res);
        int n=matrix[0].size();
        if (n==0) return(res);
        vector<vector<int>> dp(m,vector<int>(n));
        
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                res = max(res,helper(matrix,dp,i,j,m,n));   
        return(res);
    }
};