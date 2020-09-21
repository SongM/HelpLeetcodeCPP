class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string,bool> m;
        for (int i=0;i+10<=s.size();i++)
        {
            if (m.find(s.substr(i,10))!=m.end())
            {
                if (m[s.substr(i,10)]==false) res.push_back(s.substr(i,10));
                m[s.substr(i,10)]=true;
            } 
            else m[s.substr(i,10)]=false;
                
        }
        return(res);
    }
};