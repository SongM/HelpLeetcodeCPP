class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<7) return(n);
        vector<int> v = {1};
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for (int i=1;i<n;i++)
        {
            int next2 = v[i2]*2;
            int next3 = v[i3]*3;
            int next5 = v[i5]*5;
            int next = min(next2,min(next3,next5));
            if (next==next2) i2++;
            if (next==next3) i3++;
            if (next==next5) i5++;
            v.push_back(next);
        }
        return(v[n-1]);
    }
};