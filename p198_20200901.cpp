class Solution {
public:
    int rob(vector<int>& nums) {
        int with = 0;
        int without = 0;
        for (int n:nums)
        {
            int t_without = without;
            without = max(with,without);
            with = t_without + n;
        }
        return(max(with,without));
    }
};