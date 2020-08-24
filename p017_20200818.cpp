// just tedius.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> m={{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
        vector<string> res = {};
        for (auto d:digits)
        {
            vector<string> t_res(res);
            res = {};
            if (t_res.size()==0)
                for (auto c:m[int(d)-'2']) res.push_back(c);
            else
            {
                for (auto c:m[int(d)-'2']) 
                {
                    for (auto t:t_res)
                    {
                        t.insert(t.end(),c.begin(),c.end());
                        res.push_back(t);
                    }
                }
            }
        }
        return(res);
    }
};