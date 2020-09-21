class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> v;
        string curr;
        for (char c:str)
        {
            if (c==' ') {
                v.push_back(curr);
                curr = "";
                continue;
            }
            curr+=c;
            
        }
        v.push_back(curr);
        if (v.size()!=pattern.size()) return(false);
        unordered_map<string,char> m2;
        unordered_map<char, string> m1;
        for (int i=0;i<pattern.size();i++)
        {
            if (m1.find(pattern[i])==m1.end() and m2.find(v[i])==m2.end())
            {
                m1[pattern[i]] = v[i];
                m2[v[i]] = pattern[i];
                continue;
            }
            if (m1.find(pattern[i])==m1.end() or m2.find(v[i])==m2.end() or m1[pattern[i]]!=v[i] or m2[v[i]]!= pattern[i])
                return(false);
        }
        return(true);
        
    }
};