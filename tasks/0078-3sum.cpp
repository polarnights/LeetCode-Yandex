#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // cout << nums[0] << "\n";
        vector<vector<int>> results;
        int i = 0;
        int j = 1;
        int t = nums.size() - 1;
        while (i < nums.size() - 2 &&
               (nums[i] + nums[i + 1] + nums[i + 2] <= 0)) {
            while (j < t) {
                // cout << "i, j, t = " << i << ", " << j << ", " << t << "\n";
                if (nums[i] + nums[j] + nums[t] > 0) {
                    t--;
                } else if (nums[i] + nums[j] + nums[t] == 0) {
                    vector<int> temp_res = {nums[i], nums[j], nums[t]};
                    // if (results.empty()) {
                    results.push_back(temp_res);
                    // }
                    while (t > 0 && nums[t - 1] == nums[t]) {
                        t--;
                    }
                    while (j < nums.size() - 1 && nums[j + 1] == nums[j]) {
                        j++;
                    }
                    t--;
                } else {
                    j++;
                }
            }
            i++;
            // bool flag = false;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                // flag = true;
                i++;
            }
            // if (flag) i--;
            j = i + 1;
            t = nums.size() - 1;
        }
        return results;
    }
};