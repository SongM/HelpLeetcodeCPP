class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        while(n!=1)
        {
            if (m.find(n)!=m.end()) return(false);
            m.insert(n);
            int t_n = 0;
            while(n>0)
            {
                t_n += pow((n%10),2);
                n=n/10;
            }
            n = t_n;
        }
        return(true);
    }
};