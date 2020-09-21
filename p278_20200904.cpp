// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(0)) return(0);
        int lo = 0;
        int hi = n;
        while(lo+1<hi)
        {
            int mi = lo+(hi-lo)/2;
            if (isBadVersion(mi)) hi = mi;
            else lo = mi;
        }
        return(lo+1);
    }
};