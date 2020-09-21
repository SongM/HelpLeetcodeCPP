class Solution {
public:
    int numSquares(int n) {
        if (n<4) return(n);
        int res = n;
        int sqrt_n = sqrt(n);
        while(res>n/(sqrt_n*sqrt_n))
        {
            int t_res = n/(sqrt_n*sqrt_n)+numSquares(n%(sqrt_n*sqrt_n));
            if (res>t_res) res=t_res;
            sqrt_n--;
        }
        return(res);
    }
};