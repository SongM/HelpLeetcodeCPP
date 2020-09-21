class Solution {
public:
    void helper(string s, vector<string>& res, vector<int>& v, int k)
    {
        int ss = 0;
        if (k>0)
        {
            for (int i=0;i<k-1;i++) ss+=v[i];
            if (ss+v[k-1]+1*(4-k)>s.size() or ss+v[k-1]+3*(4-k)<s.size()) return;
            if (s[ss]=='0' and v[k-1]>1) return;
            if (v[k-1]==3)
            {
                if(s[ss]>'2') return;
                if(s[ss]=='2')
                {
                    if (s[ss+1]>'5') return;
                    if (s[ss+1]=='5') 
                    {if (s[ss+2]>'5') return;}
                }
            }
        }
            
        if (k==4)
        {
            ss = v[0];
            for (int i=1;i<4;i++)
            {
                s.insert(ss,".");
                ss+=v[i]+1;
            }
            res.push_back(s);
            return;
        }
        for (int i=1;i<=3;i++)
        {
            v[k] = i;
            helper(s,res,v,k+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> v={1,1,1,1};
        helper(s,res,v,0);
        return(res);
        
    }
};