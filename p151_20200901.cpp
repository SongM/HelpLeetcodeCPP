class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int start_i=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==' ')
            {
                if(i!=start_i) v.push_back(s.substr(start_i,i-start_i));
                start_i = i+1;
            }
        }
        if(s.size()!=start_i) v.push_back(s.substr(start_i,s.size()-start_i));
        if (v.size()==0) return("");
        string res = v.back();
        while(v.size()>1)
        {
            v.pop_back();
            res+=" "+v.back();
        }    
        return(res);
        
    }
};