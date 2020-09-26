class Solution {
public:
    string helper(string& s, int& i)
    {
        string res = "";
        while(1)
        {
            while(1)
            {
                if (i==s.size()) return(res);
                if (s[i]==']') {i++;return(res);}
                if (s[i]>='0' and s[i]<='9') break;
                res += s[i];
                i++;
            }
            int k=0;
            while(s[i]!='[')
            {
                k = 10*k + s[i]-'0';
                i++;
            }
            i++;
            string t_res = helper(s, i);

            for (int j=0;j<k;j++) res+=t_res;
        }
        return(res);
    }
    string decodeString(string s) {
        int i=0;
        return(helper(s,i));
        
    }
};