#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int jump(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i - 1], nums[i] + i);
        }
        int i = 0;
        int counter = 0;
        while (i != nums.size() - 1) {
            counter++;
            i = nums[i];
        }
        return counter;
    }
};