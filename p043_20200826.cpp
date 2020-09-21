
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0]=='0' or num2[0]=='0') return("0");
        vector<int> v(num1.size()+num2.size());
        for (int i=0;i<num1.size();i++)
        {
            for (int j=0;j<num2.size();j++) v[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
        }
        string res="";
        for (int i=v.size()-1;i>=1;i--)
        {
            if (v[i]>9) v[i-1]+=v[i]/10;
            res += v[i]%10+'0';
        }
        if (v[0]>0) res += v[0]%10+'0';
        reverse(res.begin(),res.end());
        return(res);
    }
};