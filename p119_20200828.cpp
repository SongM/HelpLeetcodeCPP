class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> res;
        res.push_back(1);
        if (rowIndex==0) return(res);
        for (int i=1;i<=rowIndex;i++)
        {
            int t=long(res.back())*(rowIndex-i+1)/i;
            res.push_back(t);
        }
        return(res);
    }
};