class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int digit = 1;
        for (int i=1;i<=num;i++)
        {
            if (i>=digit*2) digit = digit*2;
            res.push_back(res[i-digit]+1);
        }
        return(res);
    }
};