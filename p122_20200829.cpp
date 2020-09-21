class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return(0); 
        int i=1;
        int buy_price = prices[0];
        int res = 0;
        while(i<prices.size())
        {
            if (prices[i]<prices[i-1])
            {
                res += prices[i-1]-buy_price;
                buy_price = prices[i];
            }
            i++;
        }
        if (prices.back()>buy_price) res+=prices.back()-buy_price;
        return(res);
    }
};