#include <vector>

using namespace std;

class Solution {
  public:
    /*
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (right - left <= 1) {
            return right;
        }
        if (nums[(left + right) / 2] < target) {
            return binarySearch(nums, (left + right) / 2, right, target);
        } else {
            return binarySearch(nums, left, (left + right) / 2, target);
        }
    }
    */

    int searchInsert(vector<int> &nums, int target) {
        int right = nums.size(), left = -1;
        int mid;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
};