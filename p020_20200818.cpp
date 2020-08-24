// could use only one vector (m) to store left part
// every time a right part is encountered, pop m to say if it is valid.

class Solution {
public:
    bool isValid(string s) {
        vector<int> a;
        vector<int> b;
        vector<int> c;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(') a.push_back(i);
            else if(s[i]=='[') b.push_back(i);
            else if(s[i]=='{') c.push_back(i);
            else if(s[i]==')') 
            {
                if (a.size()==0) return(false);
                if (b.size()>0 and a.back()<b.back()) return(false);
                if (c.size()>0 and a.back()<c.back()) return(false);
                a.pop_back();
            }
            else if(s[i]==']') 
            {
                if (b.size()==0) return(false);
                if (a.size()>0 and b.back()<a.back()) return(false);
                if (c.size()>0 and b.back()<c.back()) return(false);
                b.pop_back();
            }
            else if(s[i]=='}') 
            {
                if (c.size()==0) return(false);
                if (a.size()>0 and c.back()<a.back()) return(false);
                if (b.size()>0 and c.back()<b.back()) return(false);
                c.pop_back();
            }
        }
        return(a.size()==0 and b.size()==0 and c.size()==0);
    }
};