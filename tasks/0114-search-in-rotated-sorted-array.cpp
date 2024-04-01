#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        // NOTE: nums.size() >= 1 according to constraints
        int left = 0;
        int right = nums.size();
        while (right - left > 1) {
            int mid = (right + left) / 2;
            // All values of nums are unique
            if (nums[mid] > nums[0]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (target <= nums[left] && target >= nums[0]) {
            left = 0;
        } else {
            right = nums.size();
        }
        if (nums.back() >= nums[0]) {
            left = 0;
            right = nums.size();
        }
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};