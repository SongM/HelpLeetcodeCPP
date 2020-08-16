

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<=1) return(s.size());
        vector<int> m;
        for (int i=0;i<128;i++) m.push_back(0);
        int l=0;
        int r=0;
        int res = 0;
        while(r<s.size())
        {
            if (m[s[r]]==0)
            {
                m[s[r]]=1;
                r++;
                if (res<r-l) res = r-l;
            }
            else
            {
                while(s[l]!=s[r])
                {
                    m[s[l]]=0;
                    l++;
                }
                l++;
                r++;
            }
        }
        return(res);
    }
};