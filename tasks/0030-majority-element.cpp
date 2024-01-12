#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    unordered_map<int, int> counter;
    int majorityElement(vector<int> &nums) {
        auto nums_size = nums.size();
        for (int i = 0; i < (nums_size / 2); i++) {
            counter[nums[i]]++;
        }
        for (int i = (nums_size / 2); i < nums_size; i++) {
            counter[nums[i]]++;
            if (counter[nums[i]] > nums_size / 2) {
                return nums[i];
            }
        }
        return -1;
    }
};