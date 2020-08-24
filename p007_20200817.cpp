// watch out for the boundary conditions
//
class Solution {
public:
    int reverse(int x) {
        int b_sign = 1;
        if (x<0) {
            if (x==-2147483648) return(0);
            b_sign = -1;
            x=-x;
        }
        int res = 0;
        while(x>0)
        {
            if (res>214748364) return(0);
            if (res==214748364 and x>=8) return(0);
            res = res*10 + x%10;
            x = x/10;
        }
        if (x<0) return(0);
        return(b_sign*res);
    }
};