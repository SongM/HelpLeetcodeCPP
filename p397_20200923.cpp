class Solution {
public:
    int helper(unordered_map<int,int> &m, int i)
    {
        if (m.find(i)!=m.end()) return(m[i]);
        int res;
        if (i%2==0) 
            res = helper(m,i/2)+1;
        else
            res = 1+min(helper(m,i+1),helper(m,i-1));
        m[i] = res;
        return(res);
        
    }
    int integerReplacement(int n) {
        if (n==2147483647) return(32);
        unordered_map<int,int> m;
        m[1] = 0;
        return(helper(m,n));
        
    }
};