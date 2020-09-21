class Solution {
public:
    int numTrees(int n) {
        vector<int> v={1,1,2};
        for (int i=3;i<=n;i++)
        {
            int s=0;
            for (int k=0;k<i;k++)
                s+=v[k]*v[i-k-1];
            v.push_back(s);
        }
        return(v[n]);
    }
};