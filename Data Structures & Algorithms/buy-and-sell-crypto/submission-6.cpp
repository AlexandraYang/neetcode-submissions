class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0]; //不能給 0, 這樣變成最低價是沒出現過的0 
        int max_profolio = 0;

        for (auto & p : prices) {
            min_price = min(p, min_price);
            max_profolio = max(max_profolio, p - min_price);
        }

        return max_profolio;
    }
};
