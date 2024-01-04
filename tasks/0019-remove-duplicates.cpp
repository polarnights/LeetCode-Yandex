#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // Check just in case future code can be affected by this corner-case

        // NOTE: Count sort is also available according to given problem info
        if (nums.size() == 0) {
            return 0;
        }
        auto tmp = -1;   // in order to allocate memory for tmp once
        // TODO: recall everything related to C++ memory
        for (size_t i = 1; i != nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                nums[i - 1] =
                    -101;   // number that is not in range of nums' values
            }
        }
        // Could be replaced by vector<int> to_be_removed indexes w/ additional
        // O(n) memory usage
        int current_idx = 0;
        int placement_idx = 0;
        while (current_idx < nums.size()) {
            if (nums[current_idx] != -101) {
                nums[placement_idx] = nums[current_idx];
                placement_idx++;
            }
            current_idx++;
        }
        auto prev_size = nums.size();
        for (int i = placement_idx; i < prev_size; i++) {
            nums.pop_back();
        }
        return placement_idx;
    }
};

/*
Note: apparently it was not needed to clear the rest of nums
So the task should be much easier to solve with two pointers
(as shown in the middle section of my solution)
*/