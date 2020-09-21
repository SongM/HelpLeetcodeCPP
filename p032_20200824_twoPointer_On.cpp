//notice left==right need to be satisfied,
//otherwise case like "()(()" would cause a failure.

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(') left++;
            else right++;
            if (left<right) {
                left=0;
                right=0;
                continue;
            }
            if (left==right and res<left+right) res = left+right;
        }
        left = 0;
        right = 0;
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i]==')') right++;
            else left++;
            if (right<left) {
                left=0;
                right=0;
                continue;
            }
            if (left==right and res<left+right) res = left+right;
        }
        return(res);
    }
};