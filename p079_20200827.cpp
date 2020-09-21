class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int k)
    {
        if (k==word.size()) return(true);
        if (i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[k]) return(false);
        board[i][j]='.';
        if (helper(board,word,i+1,j,k+1)) return(true);
        if (helper(board,word,i-1,j,k+1)) return(true);
        if (helper(board,word,i,j+1,k+1)) return(true);
        if (helper(board,word,i,j-1,k+1)) return(true);
        board[i][j]=word[k];
        return(false);
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size()==0) return(true);
        int m = board.size();
        if (m==0) return(false);
        int n = board[0].size();
        if (n==0) return(false);
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (helper(board,word,i,j,0)) return(true);
        return(false);
    }
};