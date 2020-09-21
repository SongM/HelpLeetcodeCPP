class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for (auto c:s) res = c-'A'+1 + res*26;
        return(res);
    }
};