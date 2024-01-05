#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        if (nums.empty()) {
            return nums;
        }
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < 0) {
                i++;
            } else {
                break;
            }
        }
        int j = i - 1;
        vector<int> result = {};
        // returns idx of first elem that is >= 0
        // or nums.size() if there is none
        // |....<--j)......|
        // |........[i-->..|
        while (j >= 0 && i < nums.size()) {
            if (nums[j] * nums[j] >= nums[i] * nums[i]) {
                result.push_back(nums[i] * nums[i]);
                i++;
            } else {
                result.push_back(nums[j] * nums[j]);
                j--;
            }
        }
        while (j >= 0) {
            result.push_back(nums[j] * nums[j]);
            j--;
        }
        while (i < nums.size()) {
            result.push_back(nums[i] * nums[i]);
            i++;
        }
        return result;
    }
};

// NOTE: finding an idx of the absolutely minimal element is excess
// and unnecessary as we can .reserve(n) in resulting vector and start
// filling numbers from highest to lowest, not vice versa.