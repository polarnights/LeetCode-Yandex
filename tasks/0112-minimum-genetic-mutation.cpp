#include <deque>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    void swapBank(vector<string> &bank, int i) {
        bank[i] = bank.back();
        bank.pop_back();
    }

    int minMutation(string startGene, string endGene, vector<string> &bank) {
        deque<pair<int, string>> order;
        order.push_back({0, startGene});

        while (!order.empty()) {
            auto cur = order.front();
            order.pop_front();
            if (cur.second == endGene) {
                return cur.first;
            }
            int i = 0;
            while (i < bank.size()) {
                int mistakes_c = 0;
                for (int j = 0; j < 8; j++) {
                    mistakes_c += (bank[i][j] != cur.second[j]);
                }
                if (mistakes_c == 1) {
                    // cout << "WAS_HERE\n";
                    order.push_back({cur.first + 1, bank[i]});
                    swapBank(bank, i);
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};