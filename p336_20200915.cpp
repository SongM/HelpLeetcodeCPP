class Solution {
public:
    bool isPalindrome(string& word1, string& word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        // if (l1==0 or l2==0) return(true);
        if (l1>=l2)
        {
            for (int i=0;i<l2;i++)
                if (word1[i]!=word2[l2-i-1]) return(false);
            for (int i=0;i<(l1-l2)/2;i++)
                if (word1[l2+i]!=word1[l1-i-1]) return(false);
        }
        else
        {
            for (int i=0;i<l1;i++)
                if (word1[i]!=word2[l2-i-1]) return(false);
            for (int i=0;i<(l2-l1)/2;i++)
                if (word2[i]!=word2[l2-l1-i-1]) return(false);
        }
        // cout<<word1<<","<<word2<<endl;
        return(true);
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        for (int i=0;i<words.size();i++)
        {
            for (int j=i+1;j<words.size();j++)
            {
                if (isPalindrome(words[i],words[j])) res.push_back({i,j});
                if (isPalindrome(words[j],words[i])) res.push_back({j,i});
            }
        }
        return(res);
    }
};