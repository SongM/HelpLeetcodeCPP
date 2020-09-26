class Solution {
public:
    int getDataLen(int num)
    {
        num = num%256;
        if (num<128) return(1);
        if (num>=192 and num<=223) return(2);
        if (num>=224 and num<=239) return(3);
        if (num>=240 and num<=247) return(4);
        return(-1);
    }
    bool startWith10(int num)
    {
        num = num%256;
        if(num<128) return(false);
        if(num>191) return(false);
        return(true);
    }
    bool validUtf8(vector<int>& data) {
        int i=0;
        while(i<data.size())
        {
            int l = getDataLen(data[i]);
            if (l==-1 or i+l>data.size()) return(false);
            for (int j=1;j<l;j++)
                if (startWith10(data[i+j])==false) return(false);
            i+=l;
        }
        return(true);
    }
};