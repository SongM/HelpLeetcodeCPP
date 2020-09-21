class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (auto s:strs)
        {
            vector<int> v(26);
            for (auto c:s) v[c-'a']+=1;
            string ss = "";
            for (int i=0;i<26;i++)
            {
                if (v[i]==0) continue;
                ss += i+'a';
                ss += v[i]+'0';
            }
            if (m.find(ss)==m.end()) m[ss]={};
            m[ss].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it:m) res.push_back(it.second);
        return(res);
    }
};