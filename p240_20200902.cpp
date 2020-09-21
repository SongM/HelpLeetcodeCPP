class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return(false);
        int n = matrix[0].size();
        if (n==0) return(false);
        
        int i=0;
        int j=n-1;
        while(i<m and j>=0)
        {
            if (matrix[i][j]==target) return(true);
            if (matrix[i][j]>target) j--;
            else i++;
        }
        return(false);
    }
};