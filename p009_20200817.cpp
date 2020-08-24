//possible other ways:
//1. convert x to string
//2. use another long int y=inv(x), return(x==y)

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return(false);
        int last_digit = x%10;
        x = x/10;
        int count = 0;
        while(pow(10,count)<=x) count++;
        count--;
        for (;count>=0;count-=2)
        {
        
            int first_digit = x/pow(10,count);
            // cout<<count<<","<<x<<endl;
            // cout<<first_digit<<","<<last_digit<<"....."<<endl;
            if (last_digit!=first_digit) return(false);
            x = x%int(pow(10,count));
            last_digit = x%10;
            x = x/10;
            
        }
        return(true);
    }
};