class Solution {
public:
    // int helper(vector<int>& coins, int amount, unordered_map<int,int>& m)
    int helper(vector<int>& coins, int amount, vector<int>& m)
    {
        
        if (amount<0) return(-1);
        // if (m.find(amount)!=m.end()) return(m[amount]);
        if (m[amount]!=-2) return(m[amount]);
        int res = amount+1;
        for (int coin:coins)
        {
            int t_res = helper(coins,amount-coin,m)+1;
            if (t_res==0) continue;
            if (res>t_res) res = t_res;
        }
        if (res==amount+1) res = -1;
        m[amount] = res;
        return(res);
    }
    int coinChange(vector<int>& coins, int amount) {
        // unordered_map<int,int> m;
        vector<int> m(amount+1,-2);
        m[0] = 0;
        return(helper(coins,amount,m));
    }
};