class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26);
        for (char c:t) v[c-'a']++;
        for (char c:s) v[c-'a']--;
        for (int i=0;i<26;i++) 
        {
            if (v[i]==1) return('a'+i);
            
        }
        return('a');
    }
};