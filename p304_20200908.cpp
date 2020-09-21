class NumMatrix {
public:
    vector<vector<int>> data;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m==0) return;
        int n = matrix[0].size();
        data.push_back(vector<int>(n+1));
        for (int i=0;i<m;i++)
        {
            data.push_back(vector<int>(n+1));
            for (int j=0;j<n;j++)
                data[i+1][j+1] = data[i+1][j] + data[i][j+1] - data[i][j] + matrix[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return(data[row2+1][col2+1]-data[row1][col2+1]-data[row2+1][col1]+data[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */