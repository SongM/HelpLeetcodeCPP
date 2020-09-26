class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if (s.size()==0) return(true);
        if (s.size()>t.size()) return(false);
        int i=0;
        int j=0;
        while(j<t.size())
        {
            if (s[i]==t[j]) i++;
            j++;
            if (i==s.size()) return(true);
        }
        return(false);
    }
};