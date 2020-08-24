class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string res = "";
        for (int i=0;i<values.size();i++)
        {
            // if (num==0) break;
            while(num>=values[i])
            {
                res += symbols[i];
                num -= values[i];
            }
        }
        return(res);
    }
};