class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        vector<int> v(26,-1);
        for (int i=0;i<n;i++)
        {
            if (v[s[i]-'a']>=0) v[s[i]-'a']=n;
            else v[s[i]-'a'] = i;
        }
        int res = n;
        for (int i=0;i<26;i++)
        {
            if (v[i]>=0 and v[i]<res) res = v[i];
        }
        return(res==n?-1:res);
    }
};