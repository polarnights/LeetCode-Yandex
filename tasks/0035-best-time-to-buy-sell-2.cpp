#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int current_profit = 0;
        int price_bought = prices[0];
        for (auto &elem : prices) {
            if (elem < price_bought) {
                price_bought = elem;
            } else {
                current_profit += (elem - price_bought);
                price_bought = elem;
            }
        }
        return current_profit;
    }
};