class Solution {
public:
    int gcd(long a, long b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
    void lowest(long& a,long& b) 
    { 
        
        int common_factor = gcd(a,b); 
        a = a / common_factor; 
        b = b / common_factor; 
    } 
  
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        unordered_set<long> m;
        for (int i=0;i+1<points.size();i++)
        {
            for (int j=i+1;j<points.size();j++)
            {
                long dx = points[i][0]-points[j][0];
                long dy = points[i][1]-points[j][1];
                if (dx==0 and dy==0) continue;
                lowest(dy,dx);
                long b=dx*points[i][1]-points[i][0]*dy;
                long key=dy*1000000+dx*1000+b;
                if (m.find(key)!=m.end()) continue;
                m.insert(key);
                int count = 0;
                for (int k=0;k<points.size();k++)
                {
                    if (dx*points[k][1]-dy*points[k][0]==b) count++;
                }
                if (res<count) res = count;
            }
        }
        if(res==0) return(points.size());
        return(res);
    }
};