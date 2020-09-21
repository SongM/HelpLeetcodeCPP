class Solution {
public:
    void helper(vector<int>& coins, int amount, int index, int t_res, int& res)
    {
        if (amount<coins.back()) return;
        // cout<<amount<<",";
        if (index == coins.size()) return;
        if (amount%coins[index]==0)
        {
            t_res += amount/coins[index];
            if (res>t_res) res = t_res;
            return;
        }
        for (int k=amount/coins[index];k>=0;k--)
        {
            if (k+t_res>=res) break;
            helper(coins, amount-k*coins[index], index+1,t_res+k,res);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0) return(0);
        sort(coins.begin(),coins.end(),greater<int>());
        int res = amount+1;
        helper(coins,amount,0,0,res);
        return(res==amount+1?-1:res);
    }
};