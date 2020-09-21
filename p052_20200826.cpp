class Solution {
public:
    void helper(int& res, vector<int>& path, int n)
    {
        if (path.size()==n) 
        {
            res++;
        }
        vector<int> line(n);
        int l=path.size();
        for (int i=0;i<l;i++)
        {
            line[path[i]]=1;
            if (path[i]-l+i>=0) line[path[i]-l+i]=1;
            if (path[i]+l-i<n) line[path[i]+l-i]=1;
        }
        for (int i=0;i<n;i++)
        {
            if (line[i]==1) continue;
            path.push_back(i);
            helper(res,path,n);
            path.pop_back();
        }
        return;
    }
    int totalNQueens(int n) {
        int res=0;
        vector<int> path;
        helper(res,path,n);
        return(res);
    }
};