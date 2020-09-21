class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i=1;i<n;i++)
        {
            string t_res = res;
            res = "";
            int count = 0;
            char digit = t_res.front();
            for (auto c:t_res)
            {
                if (c==digit) count++;
                else
                {
                    res += count+'0';
                    res += digit;            
                    count = 1;
                    digit = c;
                }
            }
            res += count+'0';
            res += digit;            
        }
        return(res);
    }
};