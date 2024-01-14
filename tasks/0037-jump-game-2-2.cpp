#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int jump(vector<int> &nums) {
        int size = nums.size();
        vector<int> min_jumps_count(size, INT_MAX);
        min_jumps_count[0] = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 1; j <= min(nums[i], size - i - 1); j++) {
                if (min_jumps_count[i + j] == INT_MAX) {
                    min_jumps_count[i + j] = min_jumps_count[i] + 1;
                }
                if (i + j == size - 1) {
                    return min_jumps_count[size - 1];
                }
            }
        }
        return min_jumps_count[size - 1];
    }
};