#include <iostream>
#include <vector>

using namespace std;

// Solution using 2 pointers

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        int current = -1;
        while (start < end && end > 0) {
            current = numbers[start] + numbers[end];
            if (current < target) {
                start++;
            } else if (current > target) {
                end--;
            } else {
                return {start + 1, end + 1};
            }
        }
        return {-1, -1};
    }
};