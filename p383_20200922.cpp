class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26);
        for (char c:magazine) m[c-'a']++;
        for (char c:ransomNote)
        {
            m[c-'a']--;
            if (m[c-'a']<0) return(false);
        }
        return(true);
    }
};