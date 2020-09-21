class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        // unordered_set<char> m={'a','e','i','o','u','A','E','I','O','U'};
        while(1)
        {
            while(i<j)
            {
                if ((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')) break;
                else i++;
            }
            while(i<j)
            {
                if ((s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')) break;
                else j--;
            }
            if (i>=j) break;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return(s);
        
    }
};