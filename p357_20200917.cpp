class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return(1);
        // if (n=1) return(10);
        int res = 10;
        int t = 9;
        int i = 9;
        while(n>1)
        {

            t *= i;
            i--;
            res += t;
            n--;
        }
        return(res);
        
    }
};