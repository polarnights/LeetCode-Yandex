#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        // NOTE: nums.size() >= 1 according to constraints
        int left = 0;
        int right = nums.size();
        while (right - left > 1) {
            int mid = (right + left) / 2;
            // Also nums[i] != nums[i + 1] (!)
            if (nums[mid] > nums[mid - 1]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};