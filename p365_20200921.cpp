class Solution {
public:
    int helper(int x, int y)
    {
        if (x>y) swap(x,y);
        if (x==0) return(y);
        if (y%x==0) return(x);
        return(helper(y-x,x));
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z==0) return(true);
        if (x==0 and y==0) return(false);
        if (x+y<z) return(false);
        return(z%helper(x,y)==0);
    }
};