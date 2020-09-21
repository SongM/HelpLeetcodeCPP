class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string s="";
        for (auto c:path)
        {
            if (c=='/')
            {
                if (s!="" and s!=".")
                {
                    if (s=="..") {if (v.size()>0) v.pop_back();}
                    else v.push_back(s);
                }
                s="";
            }
            else s=s+c;
        }
        if (s!="" and s!=".")
        {
            if (s=="..") {if (v.size()>0) v.pop_back();}
            else v.push_back(s);
        }
        s = "";
        for (auto ss:v)
            s+="/"+ss;
        if (s.size()==0) s="/";
        return(s);
    }
};