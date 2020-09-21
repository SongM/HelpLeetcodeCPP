class Solution {
public:
    vector<int> convertStringToV(string version)
    {
        vector<int> res;
        int digit=0;
        for (auto c:version)
        {
            if(c=='.')
            {
                res.push_back(digit);
                digit=0;
            }
            else digit = digit*10 + c-'0';
        }
        if (digit>0) res.push_back(digit);
        return(res);
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = convertStringToV(version1);
        vector<int> v2 = convertStringToV(version2);
        for (int i=v1.size();i<v2.size();i++) v1.push_back(0);
        for (int i=v2.size();i<v1.size();i++) v2.push_back(0);
        for (int i=0;i<v2.size();i++)
        {
            if (v1[i]>v2[i]) return(1);
            if (v1[i]<v2[i]) return(-1);
        }
        return(0);
    }
};