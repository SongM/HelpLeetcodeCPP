// this is a typical graph problem.
// make sure only visit each node for one time.
// normally such problem achieves O(n) for dfs.

class Solution {
public:
    void helper(vector<vector<string>>& res, vector<string>& t_res, unordered_map<string,unordered_set<string>>& prev_words, string& beginWord)
    {
        if (t_res.back()==beginWord) {reverse(t_res.begin(),t_res.end()); res.push_back(t_res); reverse(t_res.begin(),t_res.end()); return;}
        for (auto word:prev_words[t_res.back()])
        {
            t_res.push_back(word);
            helper(res,t_res,prev_words,beginWord);
            t_res.pop_back();
        }
        return;
    }
        
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(),wordList.end());
        vector<vector<string>> res;
        if (m.find(endWord)==m.end()) return(res);

        if (m.find(beginWord)!=m.end()) m.erase(beginWord);

        vector<string> curr_level = {beginWord};
        unordered_map<string,unordered_set<string>> prev_words;
        bool b_end = false;
        while(b_end==false and curr_level.size()>0)
        {
            vector<string> prev_level = curr_level;
            for (auto word:curr_level) m.erase(word);
            curr_level = {};
            while(prev_level.size()>0)
            {
                string word = prev_level.back();
                if (word==endWord) {b_end = true;break;}

                prev_level.pop_back();
                string prev_word = word;
                for (int i=0;i<word.size();i++)
                {
                    char c=word[i];
                    for (int j=0;j<26;j++)
                    {
                        word[i] = j+'a';
                        if (m.find(word)==m.end()) continue;
                        prev_words[word].insert(prev_word);
                        curr_level.push_back(word);
                    }
                    word[i]=c;
                }
            }
        }
        // for (auto it:prev_words)
        // {
        //     cout<<it.first<<":";
        //     for (auto iit:it.second) cout<<iit<<',';
        //     cout<<endl;
        // }
        vector<string> t_res = {endWord};
        helper(res,t_res,prev_words,beginWord);
        return(res);   
    }
};