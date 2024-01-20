/*

Kadane's Algorithm:
(Basically the same as prefix-sums, but with O(1) memory instead
for this particular case of finding a subarray with the maximal sum)

Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array

  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

*/

#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int current_max = INT_MIN;
        // pair<int, int> idxes = {-1, -1};
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            if (current_sum > current_max) {
                current_max = current_sum;
                // idxes[1] = i;
            }
            if (current_sum < 0) {
                current_sum = 0;
                // idxes[0] = i;
            }
        }
        return current_max;
    }
};