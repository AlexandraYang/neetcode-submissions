class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            if (price < min_price) {
                //如果 prices[i] < min_price：更新 min_price
                min_price = price;
            } else {
                // 否則，試著「賣出」看看 profit = prices[i] - min_price，
                // 更新最大利潤 max_profit
                max_profit = max (max_profit, price-min_price);
            }
        }

        return max_profit;
    }
};
