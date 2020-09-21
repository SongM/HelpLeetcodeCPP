class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return(1);
        if (x==0) return(0);
        double res = 1;
        if (x<0)
        {
            if (n%2==1) res = -1;
            x = -x;
        }
        if (n==-2147483648) {
            x = x*x;
            n = n/2;
        }
        if (n<0)
        {
            n = -n;
            x = 1/x;
        }
        while(n>0)
        {
            if (n%2==0)
            {
                x = x*x;
                n = n/2;
            }
            else
            {
                n=n-1;
                res = res*x;
            }
        }
        return(res);
    }
};