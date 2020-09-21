// f(1,1) = 0;
// f(1,n) = 1;
// f(m,1) = 1;
// f(m,n) = f(m-1,n) + f(m,n-1);
// f(2,n) = f(2,n-1)+f(1,n) = f(2,n-1)+1 = f(2,n-2)+2 = f(2,1)+n-1 = n
// f(m,2) = m
// f(3,n) = f(3,n-1)+f(2,n) = f(3,n-1)+n = f(3,n-2)+n+n-1 = n(n+1)/2
// f(4,n) = f(4,n-1)+(n^2+n)/2 = (n+2)(n+1)n/3/2/1
// f(5,n) = (n+3)(n+2)(n+1)n/4/3/2/1

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m>n)
        {
            int t = m;
            m = n;
            n = t;
        }
        if (m==0) return(0);
        long res = 1;
        for (int i=1;i<m;i++)
        {
            res = res*n;
            res = res/i;
            n++;
        }
        return(res);
    }
};