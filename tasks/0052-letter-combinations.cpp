#include <math.h>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<vector<char>> transfer = {{},
                                     {},
                                     {'a', 'b', 'c'},
                                     {'d', 'e', 'f'},
                                     {'g', 'h', 'i'},
                                     {'j', 'k', 'l'},
                                     {'m', 'n', 'o'},
                                     {'p', 'q', 'r', 's'},
                                     {'t', 'u', 'v'},
                                     {'w', 'x', 'y', 'z'}};
    int max_size = 0;
    string_view digits_copy;
    vector<string> result;

  public:
    void addNewCombination(string current, int idx_current) {
        if (idx_current < max_size) {
            for (auto letter : transfer[digits_copy[idx_current] - '0']) {
                addNewCombination(current + letter, idx_current + 1);
            }
        } else {
            result.push_back(current);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        result.clear();
        max_size = digits.size();
        result.reserve(pow(3, max_size));
        digits_copy = digits;
        addNewCombination("", 0);
        return result;
    }
};