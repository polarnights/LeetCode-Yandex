using namespace std;

#include <vector>
#include <string>
#include <format>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result = {};
        if (nums.empty()) {
            return result;
        }
        size_t start = 0;
        for (size_t i = 1; i != nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (i - 1 != start) {
                    // TODO: Recall difference between format and string cat
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                } else {
                    result.push_back(to_string(nums[start]));
                }
                start = i;
            }
        }
        if (nums.size() - 1 != start) {
            result.push_back(to_string(nums[start]) + "->" + to_string(nums.back()));
        } else {
            result.push_back(to_string(nums[start]));
        }
        return result;
    }
};