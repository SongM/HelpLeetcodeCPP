// not difficult
// just trivil

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++)
        {
            vector<int> v={1,2,3,4,5,6,7,8,9};
            for (int j=0;j<9;j++)
            {
                if (board[i][j]=='.') continue;
                int k = board[i][j]-'0'-1;
                if (v[k]==0) return(false);
                else v[k]=0;
            }
        }
        for (int i=0;i<9;i++)
        {
            vector<int> v={1,2,3,4,5,6,7,8,9};
            for (int j=0;j<9;j++)
            {
                if (board[j][i]=='.') continue;
                int k = board[j][i]-'0'-1;
                if (v[k]==0) return(false);
                else v[k]=0;
            }
        }
        for (int ii=0;ii<3;ii++)
        {
            for (int jj=0;jj<3;jj++)
            {
                vector<int> v={1,2,3,4,5,6,7,8,9};
                for (int i=0;i<3;i++)
                {
                    for (int j=0;j<3;j++)
                    {
                        if (board[ii*3+i][jj*3+j]=='.') continue;
                        int k = board[ii*3+i][jj*3+j]-'0'-1;
                        if (v[k]==0) return(false);
                        else v[k]=0;
                    }
                }
            }
        }
        return(true);
        
        
    }
};