class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return(0);
        int n=grid[0].size();
        if (n==0) return(0);
        int count=0;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]=='1')
                {
                    count++;
                    vector<vector<int>> s={{i,j}};
                    while(s.size()>0)
                    {
                        vector<int> p=s.back();
                        s.pop_back();
                        grid[p[0]][p[1]] = 'X';
                        if (p[0]-1>=0 and grid[p[0]-1][p[1]]=='1') s.push_back({p[0]-1,p[1]});
                        if (p[0]+1<m and grid[p[0]+1][p[1]]=='1') s.push_back({p[0]+1,p[1]});
                        if (p[1]-1>=0 and grid[p[0]][p[1]-1]=='1') s.push_back({p[0],p[1]-1});
                        if (p[1]+1<n and grid[p[0]][p[1]+1]=='1') s.push_back({p[0],p[1]+1});

                    }
                }
            }
        }
        return(count);
    }
};