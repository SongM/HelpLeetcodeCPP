class Trie {
public:
    /** Initialize your data structure here. */
    vector<Trie*> data; 
    bool b_word;
    Trie() {
        for (int i=0;i<26;i++) data.push_back(NULL);
        b_word = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        vector<Trie*>* d = &data;
        
        Trie* t;
        for (char c:word)
        {
            if ((*d)[c-'a']==NULL) (*d)[c-'a'] = new Trie();
            t = (*d)[c-'a'];
            d = &(t->data);
        }
        t->b_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        vector<Trie*>* d = &data;
        Trie* t;
        for (char c:word)
        {
            if ((*d)[c-'a']==NULL) return(false);
            t = (*d)[c-'a'];
            d = &(t->data);
        }

        return(t->b_word);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        vector<Trie*>* d = &data;
        Trie* t;
        for (char c:prefix)
        {
            if ((*d)[c-'a']==NULL) return(false);
            t = (*d)[c-'a'];
            d = &(t->data);
        }
        return(true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */