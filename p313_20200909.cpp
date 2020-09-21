class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int l = primes.size();
        vector<int> is(l);
        vector<int> v;
        v.push_back(1);
        for (int i=1;i<n;i++)
        {
            int next = v[is[0]]*primes[0];
            for (int j=1;j<l;j++)
                next = min(v[is[j]]*primes[j],next);
            v.push_back(next);
            for (int j=0;j<l;j++)
            {
                if(next==v[is[j]]*primes[j]) is[j]++;
            }
        }
        // for (int i:v) cout<<i<<",";
        // cout<<endl;
        return(v.back());
    }
};