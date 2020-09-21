class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m==0) return;
        int n = board[0].size();
        if (n==0) return;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int count = 0;
                if (i-1>=0 and abs(board[i-1][j])==1) count++;
                if (i+1<m and board[i+1][j]==1) count++;
                if (j-1>=0 and abs(board[i][j-1])==1) count++;
                if (j+1<n and board[i][j+1]==1) count++;
                if (i-1>=0 and j-1>=0 and abs(board[i-1][j-1])==1) count++;
                if (i-1>=0 and j+1<n and abs(board[i-1][j+1])==1) count++;
                if (i+1<m and j-1>=0 and board[i+1][j-1]==1) count++;
                if (i+1<m and j+1<n and board[i+1][j+1]==1) count++;
                
                if (board[i][j]==1)
                {
                    if (count<2 or count>3) board[i][j] = -1;
                }
                else
                {
                    if (count==3) board[i][j] = 2;
                }
            }
        }
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (board[i][j]==2) board[i][j]=1;
                else if (board[i][j]==-1) board[i][j]=0;
            }
        }
    }
    
    
};