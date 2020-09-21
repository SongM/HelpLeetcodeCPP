class Solution {
public:
    int countPrimes(int n) {
        if (n<2) return(0);
        if (n<4) return(n-2);
        vector<int> v(n,1);
        v[0] = 0;
        v[1] = 0;
        int count = 0;
        for (int i=2;i<n;i++)
        {
            if (v[i]==0) continue;
            count++;
            for (int j=i+i;j<n;j+=i) v[j]=0; 
        }
        return(count);
    }
};