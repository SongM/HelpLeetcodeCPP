class Solution {
public:
    bool helper(string& num, int i, int j, int k)
    {
        long n1 = stol(num.substr(i,j-i));
        long n2 = stol(num.substr(j,k-j));
        // cout<<n1<<","<<n2<<endl;
        long n3 = n1+n2;
        if (n3>0 and num[k]=='0') return(false);
        string str3 = to_string(n3);
        int l = str3.size();
        if (k+l>num.size() or str3!=num.substr(k,l)) return(false);
        if (k+l==num.size()) return(true);
        return(helper(num,j,k,k+l));
    }
    bool isAdditiveNumber(string num) {
        for (int j=1;j<num.size();j++)
        {
            for (int k=j+1;k<num.size();k++)
            {
                if (helper(num,0,j,k)) return(true);
                if(num[j]=='0') break;
            }
            if (num[0]=='0') break;

        }
        return(false);

    }
};