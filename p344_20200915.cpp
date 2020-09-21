class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
        // int l = s.size();
        // for (int i=0;i<l/2;i++)
        //     swap(s[i],s[l-i-1]);
        return;
    }
};