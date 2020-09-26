class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = t.back();
        for (int i=0;i<s.size();i++) res = res+t[i]-s[i];
        return(char(res));
    }
};