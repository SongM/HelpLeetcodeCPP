class Solution {
public:
    int romanToInt(string s) {
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int res = 0;
        int pos = 0;
        for (int i=0;i<values.size();i++)
        {
            int l=symbols[i].size();
            while(pos+l<=s.size() and symbols[i].compare(s.substr(pos,l))==0)
            {
                res += values[i];
                pos += l;
            }
        }
        return(res);
    }
};