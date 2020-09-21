class Solution {
public:
    int convertAChar(char c)
    {
        if (c>='a' and c<='z') return(c-'a'+10);
        if (c>='A' and c<='Z') return(c-'A'+10);
        if (c>='0' and c<='9') return(c-'0');
        return(-1);
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            int a=convertAChar(s[i]);
            if (a<0) {i++;continue;}
            int b=convertAChar(s[j]);
            if (b<0) {j--;continue;}
            if (a!=b) return(false);
            i++;
            j--;
        }
        return(true);
    }
};