class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int b_sign = 1;
        if (numerator==0) return("0");
        long long_denominator = denominator;
        long long_numerator = numerator;
        if (denominator<0)
        {
            b_sign = -b_sign;
            long_denominator = -long_denominator;
        }
        if (numerator<0)
        {
            b_sign = -b_sign;
            long_numerator = -long_numerator;
        }
        
        
        
        long before_dot = long_numerator/long_denominator;
        long_numerator = long_numerator%long_denominator;
        int count = 0;
        unordered_map<long,int> m;
        string t_res = "";
        while(long_numerator>0)
        {
            if (m.find(long_numerator)!=m.end())
            {
                break;
            }
            int digit=long_numerator*10/long_denominator;
            m[long_numerator] = count++;
            t_res += digit+'0';
            long_numerator = (long_numerator*10)%long_denominator;
        }
        string res="";
        if (b_sign==-1) res+="-";
        res += to_string(before_dot);
        if (long_numerator==0)
        {
            if (t_res.size()>0) res +="."+t_res;
            return(res);
        }
        res+="."+t_res.substr(0,m[long_numerator])+"("+t_res.substr(m[long_numerator])+")";
        return(res);
        
    }
};