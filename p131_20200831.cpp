class Solution {
public:
    bool isPalindrome(string& s, int i, int j)
    {
        while(i<j)
            if (s[i++]!=s[j--]) return(false);
        return(true);
    }
    void helper (vector<vector<string>>& res, vector<string>& t_res, string s, int k)
    {
        if (k==s.size()) {res.push_back(t_res);return;}
        for (int i=k;i<s.size();i++)
        {
            if (isPalindrome(s,k,i)==false) continue;
            t_res.push_back(s.substr(k,i-k+1));
            helper(res,t_res,s,i+1);
            t_res.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> t_res;
        helper(res,t_res,s,0);
        return(res);
        
    }
};