class Solution {
public:
    bool isPerfectSquare(int num) {
        long lo = 1;
        long hi = num/2;
        while(lo<hi)
        {
            long mi = lo + (hi-lo)/2;
            if (mi*mi==num) return(true);
            if (mi*mi<num) lo = mi+1;
            else hi = mi;
        }
        cout<<lo;
        return(lo*lo==num);
    }
};