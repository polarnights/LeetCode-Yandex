#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int current_min = INT_MAX;
        int current_profit = 0;
        for (auto &elem : prices) {
            if (elem < current_min) {
                current_min = elem;
            } else {
                auto diff = elem - current_min;
                if (diff > current_profit) {
                    current_profit = diff;
                }
            }
        }
        return current_profit;
    }
};