class Solution {
public:
    int helper(string& s, int k, int l, int r)
    {
        if (r-l<k) return(0);
        unordered_map<char,int> m;
        for (int i=l;i<r;i++) m[s[i]]++;
        bool all_smaller_than_k = true;
        bool all_greater_than_k = true;
        for (auto it:m) 
        {
            all_smaller_than_k = all_smaller_than_k and (it.second<k);
            all_greater_than_k = all_greater_than_k and (it.second>=k);
        }
        if (all_smaller_than_k==true) return(0);
        if (all_greater_than_k==true) return(r-l);
        int i=l;
        while(m[s[i]]>=k) i++;
        int j=i+1;
        while(j<r and m[s[j]]<k) j++;
        int res = helper(s,k,l,i);
        if (res<r-j) res = max(res,helper(s,k,j,r));                      
        return(res);
        
    }
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size());
    }
};