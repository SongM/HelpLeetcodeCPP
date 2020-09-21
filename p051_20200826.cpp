class Solution {
public:
    void helper(vector<vector<string>>& res, vector<int>& path, int n)
    {
        if (path.size()==n) 
        {
            vector<string> s;
            string str="";
            for (int i=0;i<n;i++) str+=".";
            for (int i=0;i<n;i++)
            {
                str[path[i]]='Q';
                s.push_back(str);
                str[path[i]]='.';
            }
            res.push_back(s);
            return;
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> path;
        helper(res,path,n);
        return(res);
        
    }
};