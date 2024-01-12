#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int current_max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > current_max) {
                return false;
            }
            current_max = max(current_max, i + nums[i]);
            if (current_max >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
    // This idea is actually pretty cool :)
};