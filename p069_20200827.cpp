// watch out for overflow

class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return(x);
        int lo = 1;
        int hi = x/2;
        while(1)
        {
            long mi = lo + (hi-lo)/2;
            if (mi*mi<=x and (mi+1)*(mi+1)>x)
                return(mi);
            if (mi*mi>x) hi = mi;
            else lo = mi+1;
        }
        return(0);
    }
};