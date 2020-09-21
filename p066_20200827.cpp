class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        digits.push_back(0);
        for (int i=0;i<digits.size();i++)
        {
            digits[i]+=1;
            if (digits[i]<10) break;
            digits[i]=0;
        }
        if(digits.back()==0) digits.pop_back();
        reverse(digits.begin(),digits.end());
        return(digits);
        
        
    }
};