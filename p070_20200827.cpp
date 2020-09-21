class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return(1);
        int with_prev = 1;
        int without = 1;
        for (int i=2;i<n;i++)
        {
            int t = with_prev;
            with_prev += without;
            without = t;
        }
        return(with_prev+without);
            
    }
};