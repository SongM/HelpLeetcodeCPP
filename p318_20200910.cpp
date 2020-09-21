class Solution {
public:
    bool shareCoommonLetters(vector<bool>& v1, vector<bool>& v2)
    {
        for (int i=0;i<26;i++) 
            if (v1[i]&&v2[i]) return(true);
        return(false);
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<bool>> alphabet(n,vector<bool>(26));
        vector<int> lens(n);
        int max_len = 0;
        for (int i=0;i<n;i++)
        {
            lens[i] = words[i].size();
            if (max_len<lens[i]) max_len = lens[i];
            for (char c:words[i]) alphabet[i][c-'a'] = true;
        }
        int res = 0;
        for (int i=0;i<n-1;i++)
        {
            if (res>=lens[i]*max_len) continue;
            for (int j=i+1;j<n;j++)
            {
                if (res>=lens[i]*lens[j] or shareCoommonLetters(alphabet[i],alphabet[j])) continue;
                res = lens[i]*lens[j];
            }
        }
        return(res);
    }
};