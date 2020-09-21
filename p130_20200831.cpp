class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m<=2) return;
        int n = board[0].size();
        if (n<=2) return;
        vector<vector<int>> s;
        for (int i=0;i<m;i++) {s.push_back({i,0});s.push_back({i,n-1});}
        for (int j=0;j<n;j++) {s.push_back({0,j});s.push_back({m-1,j});}
        while(s.size()>0)
        {
            vector<int> p=s.back();
            s.pop_back();
            if (board[p[0]][p[1]]!='O') continue;
            board[p[0]][p[1]] = 'Y';
            if (p[0]-1>0) s.push_back({p[0]-1,p[1]});
            if (p[0]+1<m-1) s.push_back({p[0]+1,p[1]});
            if (p[1]-1>0) s.push_back({p[0],p[1]-1});
            if (p[1]+1<n-1) s.push_back({p[0],p[1]+1});
        }
        for (int i=0;i<m;i++) 
        {
            for (int j=0;j<n;j++)
            {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='Y') board[i][j]='O';
            }
        }
        return;
    }
};