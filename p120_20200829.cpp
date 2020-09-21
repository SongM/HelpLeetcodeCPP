class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=1;i<triangle.size();i++)
        {
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for (int j=1;j<i;j++) triangle[i][j] += triangle[i-1][j-1]<triangle[i-1][j]?triangle[i-1][j-1]:triangle[i-1][j];
        }
        int res = triangle[triangle.size()-1][0];
        for (int j=1;j<triangle.size();j++)
            res = res<triangle[triangle.size()-1][j]?res:triangle[triangle.size()-1][j];
        return(res);
    }
};