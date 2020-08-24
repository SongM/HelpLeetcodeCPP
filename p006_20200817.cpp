// watch out for the boundary condition
//

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size()<=numRows or numRows==1) return(s);
        string res="";
        for (int i=0;i<s.size();i+=2*numRows-2)
            res += s[i];
        for (int row=1;row<numRows-1;row++)
        {
            for (int i=row;i<s.size();i+=2*numRows-2)
            {
                res += s[i];
                if (i+2*numRows-2-2*row<s.size())
                    res += s[i+2*numRows-2-2*row];
            }
            
        }
        for (int i=numRows-1;i<s.size();i+=2*numRows-2)
            res += s[i];
        // cout<<res;
        return(res);
    }
};