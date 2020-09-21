class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int carry = 0;
        string res="";
        while(i<a.size() or i<b.size())
        {
            if (i<a.size() and a[i]=='1') carry++;
            if (i<b.size() and b[i]=='1') carry++;
            res += carry%2 + '0';
            if (carry>1) carry = 1;
            else carry = 0;
            i++;
        }
        if (carry==1) res+='1';
        reverse(res.begin(),res.end());
        return(res);
    }
};