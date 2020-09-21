//change the type of a accordingly

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        for (int i=1;i<=n;i++) res+=i+'0';
        if (k==1) return(res);
        vector<int> v={1};
        for (int i=2;i<n;i++) v.push_back(v.back()*i);
        for (int i=0;i<n-1;i++)
        {
            if (k==1) break;
            if (k>v.back())
            {
                int j=(k-1)/v.back();
                k = (k-1)%v.back()+1;
                string t=res.substr(i+j,1);
                res.erase(i+j,1);
                res.insert(i,t);
            }
            v.pop_back();
            
        }
        return(res);
            
    }
};