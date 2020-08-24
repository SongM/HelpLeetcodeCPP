// notice there are two types of Palindromic: even and odd:
// like aba and abba
// check both case
//
// i is used as the palindromic centor
// j is used as the max possible half length
class Solution {
public:
    string longestPalindrome(string s) {
        
        int l=s.size();
	int j;
        if (l<2) return s;
        string res = s.substr(0,1);
        for(int i=0;i<l;i++)
        {  
            j=i<l-i-1?i:l-i-1;
            for (int k=1;k<=j;k++)
            {
                if (s[i-k]==s[i+k])
                {
                    if (2*k+1>res.size()) res = s.substr(i-k,2*k+1);
                }
                else break;
            }
            j=i<l-i?i:l-i;
            for (int k=1;k<=j;k++)
            {
                if (s[i-k]==s[i+k-1])
                {
                    if (2*k>res.size()) res = s.substr(i-k,2*k);
                }
                else break;
            }
        }
        return res;
    }
};