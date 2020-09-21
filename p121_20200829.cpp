class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return(0);
        int buy_price = prices[0];
        int res = 0;
        for (int i=1;i<prices.size();i++)
        {
            if (prices[i]>buy_price) res = res>(prices[i]-buy_price)?res:(prices[i]-buy_price);
            else buy_price = prices[i];
        }
        return(res);
    }
};