class Solution {
public:
    int lastRemaining(int n) {
        
        int start_i = 1;
        int end_i = n;
        int interval = 1;
        while(start_i!=end_i)
        {
            if ((end_i-start_i)%(interval*2)!=0) end_i = end_i + interval;
            int new_start_i = end_i-interval;
            end_i = start_i + interval;
            start_i = new_start_i;
            interval = -interval*2;
        }
        return(start_i);
    }
};