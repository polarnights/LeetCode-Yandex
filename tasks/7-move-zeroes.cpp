#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t current_pos = 0;
        size_t number_pos = 0;
        while (number_pos < nums.size()) {
            if (nums[number_pos] != 0) {
                nums[current_pos] = nums[number_pos];
                current_pos++;
            }
            number_pos++;
        }
        for (int i = current_pos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};