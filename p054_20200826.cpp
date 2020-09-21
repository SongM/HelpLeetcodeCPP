class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if (m==0) return(res);
        int n=matrix[0].size();
        if (n==0) return(res);
        int count = 0;
        int i=0;
        int j=0;
        while(1)
        {
            if (count>n-count-1) break;
            for (int j=count;j<=n-count-1;j++)
                res.push_back(matrix[count][j]);
            if (count+1>m-count-1) break;
            for (int i=count+1;i<=m-count-1;i++)
                res.push_back(matrix[i][n-count-1]);

            if (n-count-2<count) break;
            for (int j=n-count-2;j>=count;j--)
                res.push_back(matrix[m-count-1][j]);
            if (m-count-2<count+1) break;
            for (int i=m-count-2;i>=count+1;i--)
                res.push_back(matrix[i][count]);

            count++;
            
        }
        return(res);
    }
};