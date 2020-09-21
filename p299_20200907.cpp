class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int l=secret.size();
        for (int i=0;i<l;i++)
            if (secret[i] == guess[i]) A++;
        int B = 0;
        sort(secret.begin(),secret.end());
        sort(guess.begin(),guess.end());
        cout<<secret<<endl;
        cout<<guess<<endl;
        int i=0;
        int j=0;
        while(i<l and j<l)
        {
            if (secret[i]==guess[j]) {i++;j++;B++;continue;}
            if (secret[i]>guess[j]) j++;
            else i++;
        }
        return(to_string(A)+"A"+to_string(B-A)+"B");
    }
};