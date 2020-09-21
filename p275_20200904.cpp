class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n==0 or citations.back()==0) return(0);
        int lo = 0;
        int hi = n-1;
        while(lo<hi)
        {
            int mi = lo + (hi-lo)/2;
            // cout<<mi<<n-mi<<citations[mi]<<endl;
            if (citations[mi]==n-mi) return(citations[mi]);
            if (citations[mi]<n-mi) lo = mi+1;
            else hi = mi;
        }
        return(n-lo);
        
    }
};