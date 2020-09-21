class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 1;
        while(m>0 and m!=n)
        {
            m = m/2;
            n = n/2;
            count = count*2;
        }
        return(m*count);
    }
};