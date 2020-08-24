// list all the boundary conditions before coding.

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        int b_sign = 1;
        if (dividend==-2147483648 and divisor==-1) return(2147483647);
        if (divisor==-2147483648)
        {
            if (dividend==-2147483648) return(1);
            else return(0);
        }
        if (divisor==1 or divisor==-1) return(dividend*divisor);
        if (divisor<0) 
        {
            b_sign = -b_sign;
            divisor = -divisor;
        }
        if (dividend==-2147483648)
        {
            res += 1;
            dividend = dividend+divisor;
        }
        if (dividend<0)
        {
            b_sign = -b_sign;
            dividend = -dividend;
        }
        // if (divisor==1) return(b_sign*dividend);
        vector<int> v;
        vector<int> vv;
        v.push_back(divisor);
        vv.push_back(1);
        while(v.back()<1073741824 and v.back()+v.back()<dividend)
        {
            v.push_back(v.back()+v.back());
            vv.push_back(vv.back()+vv.back());
        }
        while(dividend>=divisor)
        {
            if (dividend>=v.back())
            {
                res+=vv.back();
                dividend-=v.back();
            }
            v.pop_back();
            vv.pop_back();
        }
        return(b_sign*res);
    }
};