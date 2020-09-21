class Solution {
public:
    int helper(string& preorder,int i)
    {
        // cout<<i<<endl;
        if (i>=preorder.size()) return(-1);
        if (preorder[i]=='#') return(i);
        int left_start = -1;;
        for (int k=i+1;k<preorder.size();k++)
        {
            if (preorder[k]==',') {
                left_start = k+1;
                break;
            }
        }
        if (left_start==-1) return(-1);
        int left_end = helper(preorder, left_start);
        if (left_end==-1) return(-1);
        int right_start = left_end+2;
        // cout<<"right_start: "<<right_start<<endl;
        return(helper(preorder, right_start));
    }
    bool isValidSerialization(string preorder) {
        return(helper(preorder,0)==preorder.size()-1);
    }
};