// not difficult just tedius

class Solution {
public:
    int myAtoi(string str) {
        int b_sign = 1;
        int i=0;
        for (;i<str.size();i++){
            
            if (str[i]==' ') continue;
            if (str[i]=='-') {i++;b_sign=-1;break;}
            if (str[i]=='+') {i++;break;}
            if (str[i]>='0' and str[i]<='9') break;
            return(0);
        }
        int res = 0;
        for(;i<str.size();i++)
        {
            int digit = str[i]-'0';
            // cout<<res<<","<<digit<<endl;
            if (digit<0 or digit>9) break;
            if (res>214748364 or (res==214748364 and digit>=8)) 
            {
                if(b_sign==-1) return(-2147483648);
                else return(2147483647);
            }
            res=res*10+digit;
        }
        return(b_sign*res);
    }
};