class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0;
        int res_i=-1;
        int ss=0;
        for (int i=0;i<gas.size();i++)
        {
            ss += gas[i]-cost[i];
            s += gas[i]-cost[i];
            if (s<0) {s=0;res_i=-1;continue;}
            if (res_i==-1 and s>=0) res_i=i;
            // cout<<ss<<res_i;
        }
        return(ss>=0?res_i:-1);
    }
};