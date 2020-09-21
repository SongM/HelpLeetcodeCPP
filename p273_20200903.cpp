class Solution {
public:
    string threeDigitToWords(int d1, int d2, int d3)
    {
        vector<string> number0To9={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string> number10To19={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> number20To90={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

        string res;
        if (d1==0)
        {
            if (d2==0) return(number0To9[d3]);
            if (d2==1) return(number10To19[d3]);
            if (d3==0) return(number20To90[d2]);
            return(number20To90[d2]+" "+number0To9[d3]);
        }
        res+= number0To9[d1]+" Hundred";
        if (d2==0 and d3==0) return(res);
        res+=" ";
        if (d2==0) return(res+number0To9[d3]);
        if (d2==1) return(res+number10To19[d3]);
        if (d3==0) return(res+number20To90[d2]);
        return(res+number20To90[d2]+" "+number0To9[d3]);
    }
    string numberToWords(int num) {
        if (num==0) return("Zero");
        string res;
        vector<string> digitKMB={" Billion"," Million"," Thousand",""};
        while(num>0)
        {
            int d3 = num%10;
            num = num/10;
            int d2 = num%10;
            num = num/10;
            int d1 = num%10;
            num = num/10;
            string t_res = threeDigitToWords(d1,d2,d3);
            if (res=="" and t_res=="") res=t_res;
            else if(res=="") res = t_res+digitKMB.back();
            else if(t_res=="") res = res;
            else res = t_res + digitKMB.back() + " " + res;
            digitKMB.pop_back();
            // cout<<d1<<d2<<d3<<endl;
            
        }
        return(res);
    }
};