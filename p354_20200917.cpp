bool firstelement(vector<int>& a, vector<int>& b) 
{   
    if (a[0]==b[0]) return(a[1]>b[1]);
    return(a[0]<b[0]);
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size()<2) return(envelopes.size());
        sort(envelopes.begin(),envelopes.end(),firstelement);
        vector<int> v;
        v.push_back(envelopes[0][1]);
        for (auto& p:envelopes)
        {
            if (p[1]>v.back()) v.push_back(p[1]);
            else if(p[1]<=v[0]) v[0] = p[1];
            else
            {
                int lo = 0;
                int hi = v.size()-1;
                while(lo+1<hi)
                {
                    int mi = (lo+hi)/2;
                    if (p[1]>v[mi]) lo = mi;
                    else hi = mi;
                }
                v[hi] = p[1];
            }
        }
        return(v.size());

    }
};