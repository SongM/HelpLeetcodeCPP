class Solution {
public:
    bool isPalindrome (string& str)
    {
        int l = str.size();
        for (int i=0;i<l/2;i++)
            if (str[i]!=str[l-i-1]) return(false);
        return(true);
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        vector<vector<int>> res;
        for (int i=0;i<words.size();i++)
            m[words[i]] = i;
        if (m.find("")!=m.end())
        {
            for (auto word:words)
            {
                if (word!="" and isPalindrome(word)) res.push_back({m[word],m[""]});
            }
        }
        for (int i=0;i<words.size();i++)
        {
            int l=words[i].size();
            for (int j=1;j<=l;j++)
            {
                string front = words[i].substr(0,j);
                string back = words[i].substr(j,l-j);
                // cout<<front<<","<<back<<endl;
                if (isPalindrome(front)) 
                {
                    reverse(back.begin(),back.end());
                    if (m.find(back)!=m.end() and i!=m[back]) res.push_back({m[back],i});
                }
                if (isPalindrome(back)) 
                {
                    reverse(front.begin(),front.end());
                    if (m.find(front)!=m.end() and i!=m[front]) res.push_back({i,m[front]});
                }
            }
        }
        return(res);
    }
};