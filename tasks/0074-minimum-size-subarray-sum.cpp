#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0;
        int j = 0;
        int cur_sum = 0;
        int min_length = INT_MAX;
        while (j < nums.size()) {
            // cout << "Start | j = " << j << " | i = " << i << "\n";
            while (j < nums.size() && cur_sum < target) {
                cur_sum += nums[j];
                j++;
            }
            // cout << "After while | j = " << j << " | i = " << i << " |
            // cur_sum = " << cur_sum << "\n";
            if (cur_sum < target) {
                return min_length == INT_MAX ? 0 : min_length;
            }
            // cout << "After if | j = " << j << " | i = " << i << "\n";
            while (cur_sum - nums[i] >= target) {
                cur_sum -= nums[i];
                i++;
            }
            // cout << "After while-2 " << j << " | i = " << i << "\n";
            if (j - i < min_length) {
                // cout << j << " - " << i << "\n";
                min_length = j - i;
            }
            // cout << "End of loop | j = " << j << " | i = " << i << "\n";
            cur_sum -= nums[i];
            i++;
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};