class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        while (1)
        {
            if (n-digit*9*pow(10,digit-1)<=0) break;
            n = n-digit*9*pow(10,digit-1);
            digit++;
        }
        int i = pow(10,digit-1);
        i+=(n-1)/digit;
        n = (n-1)%digit;
        for (int ii=1;ii<digit-n;ii++) i = i/10;
        return(i%10);
    }
};