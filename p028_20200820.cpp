// notice that needle.size() return a uint
// when uint a < uint b
// a-b is not a negative int but a uint variable with very large positive value.


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size()<needle.size()) return(-1);
        int l_boundary = haystack.size() - needle.size();
        for (int i=0;i<=l_boundary;i++)
        {
            bool b_return = true;
            for (int j=0;j<needle.size();j++)
            {
                if (haystack[i+j]!=needle[j])
                {
                    b_return = false;
                    break;
                }
            }
            if (b_return) return(i);
        }
        return(-1);
    }
};