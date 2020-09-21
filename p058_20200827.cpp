class Solution {
public:
    bool isALetter(char c)
    {
        if (c>='a' and c<='z') return(true);
        if (c>='A' and c<='Z') return(true);
        return(false);
    }
    int lengthOfLastWord(string s) {
        
        int n=s.size();
        while(n>=0)
        {
            if (isALetter(s[n])) break;
            else n--;
        }
        int count=0;
        while(n>=0)
        {
            if (isALetter(s[n])) {n--;count++;}
            else break;
        }
        return(count);
    }
};