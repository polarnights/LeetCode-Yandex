#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int saved = INT_MIN;
        int count = 0;
        int placement_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != saved) {
                saved = nums[i];
                count = 1;
                nums[placement_idx] = nums[i];
                placement_idx++;
            } else {
                if (count == 2) {
                    continue;
                } else {
                    count++;
                    nums[placement_idx] = nums[i];
                    placement_idx++;
                }
            }
        }
        return placement_idx;
    }
};