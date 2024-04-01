#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        if (nums.size() == 1) {
            if (nums[0] == target)
                return {0, 0};
            return {-1, -1};
        }
        int left = 0;
        int right = nums.size();
        int left2 = 0;
        int right2 = nums.size();
        while (right - left > 1 || right2 - left2 > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
            mid = (left2 + right2) / 2;
            if (nums[mid] >= target) {
                right2 = mid;
            } else {
                left2 = mid;
            }
        }
        if (nums[left] == target)
            return {nums[left2] == target ? left2 : right2, left};
        return {-1, -1};
    }
};

/*
Code is a bit weird cause it does not include std lib functions
Should recall how to use those anyway
*/