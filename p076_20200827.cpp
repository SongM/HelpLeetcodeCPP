class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()==0 or s.size()<t.size()) return("");
        unordered_map<char,int> m;
        vector<int> v(26);
        for (auto c:t) 
        {
            if (m.find(c)==m.end()) m[c]=1;
            else m[c]++;
        }
        unordered_map<char,int> mm=m;
        int i=0;
        int j=0;
        int res_i=0;
        int res_j=s.size()+1;
        bool valid=false;
        while(j<s.size() or valid)
        {
            if (valid==false)
            {                
                if (m.find(s[j])!=m.end()) 
                {
                    mm[s[j]]--;
                    if (mm[s[j]]==0)
                    {
                        valid = true;
                        for (auto it:mm) {if (it.second>0) {valid=false;break;}}
                    }
                }
                j++;
            }
            else
            {
                if (m.find(s[i])!=m.end()) 
                {
                    mm[s[i]]++;
                    if (mm[s[i]]==1)
                    {
                        valid = false;
                        if (res_j-res_i>j-i) {res_i=i;res_j=j;}
                    }
                }
                i++;
            }
        }
        // cout<<res_i<<","<<res_j<<endl;
        if(res_j==s.size()+1) return("");
        return(s.substr(res_i,res_j-res_i));
    }
};