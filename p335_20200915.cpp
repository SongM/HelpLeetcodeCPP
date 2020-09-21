class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i=3;i<x.size();i++)
        {
            // cout<<i<<endl;
            int yy = x[i-3]-x[i-1];
            int xx = -x[i-2]+x[i];
            // cout<<xx<<","<<yy<<endl;
            if (xx>=0 and yy>=0 and yy<=x[i-3]) return(true);
            if (i>=4)
            {
                yy = x[i-4]-x[i-2]+x[i];
                xx = -x[i-3]+x[i-1];
                // cout<<xx<<","<<yy<<endl;
                if (xx==0 and yy>=0) return(true);
            }
            if (i>=5)
            {
                yy = x[i-5]-x[i-3]+x[i-1];
                xx = -x[i-4]+x[i-2];
                // cout<<xx<<","<<yy<<endl;
                if (xx>=0 and yy>=0 and yy<=x[i-5] and xx-x[i]<=0) return(true);
            }
                
        }
        return(false);
    }
};