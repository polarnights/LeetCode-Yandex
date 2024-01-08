#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int solve(vector<int> &numbers) {
        if (numbers.empty()) {
            return INT_MIN;   // does not exist
        }
        int max = numbers[0];
        int second_max = INT_MIN;
        for (int i = 1; i != numbers.size(); i++) {
            if (numbers[i] >= max) {
                // Suggesting that if there are >= 2 equal MAX elements
                // We consider second_max == max
                second_max = max;
                max = numbers[i];
            } else if (numbers[i] > second_max) {
                second_max = numbers[i];
            }
        }
        return second_max;
    }
};

int
main() {
    Solution solution;
    vector<int> numbers = {0, 1, 2, 4, 3, -1, 2, -93};
    cout << solution.solve(numbers) << "\n";
}