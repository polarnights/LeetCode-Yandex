#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> result(nums.size(), 1);
        int current = 1;
        for (size_t i = 0; i <= nums.size() - 1; i++) {
            result[i] *= current;
            current *= nums[i];
        }
        current = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= current;
            current *= nums[i];
        }
        return result;
    }
};