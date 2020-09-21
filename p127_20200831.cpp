class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(),wordList.end());
        if (m.find(endWord)==m.end()) return(0);
        vector<string> curr_level = {beginWord};
        if (m.find(beginWord)!=m.end()) m.erase(beginWord);
        int res = 1;
        while(curr_level.size()>0)
        {
            vector<string> prev_level = curr_level;
            curr_level = {};
            while(prev_level.size()>0)
            {
                string word = prev_level.back();
                if (word==endWord) return(res);
                prev_level.pop_back();
                
                for (int i=0;i<word.size();i++)
                {
                    char c=word[i];
                    for (int j=0;j<26;j++)
                    {
                        word[i] = j+'a';
                        if (m.find(word)==m.end()) continue;
                        curr_level.push_back(word);
                        m.erase(word);
                    }
                    word[i]=c;
                }
            }
            res++;
        }

        return(0);
    }
};