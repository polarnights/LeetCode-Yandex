#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int candy(vector<int> &ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        int size = ratings.size();
        vector<int> candys(size, 1);
        for (int i = 1; i < size - 1; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candys[i] = candys[i - 1] + 1;
            }
        }
        for (int i = 1; i < size - 1; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candys[i] = max(candys[i], candys[i - 1] + 1);
            }
            if (ratings[size - 1 - i] > ratings[size - i]) {
                candys[size - 1 - i] =
                    max(candys[size - 1 - i], candys[size - i] + 1);
            }
        }
        if (ratings[0] > ratings[1]) {
            // cout << "Corner 1\n";
            candys[0] = candys[1] + 1;
        }
        if (ratings[size - 1] > ratings[size - 2]) {
            // cout << "Corner 2\n";
            candys[size - 1] = candys[size - 2] + 1;
        }
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += candys[i];
            // cout << candys[i] << "\n";
        }
        return total;
    }
};