#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // [min; max)
    int binarySearch(vector<int> &numbers, int min, int max, int given,
                     int target) {
        if (max - min > 1) {
            if (given + numbers[(max + min) / 2] > target) {
                return binarySearch(numbers, min, (max + min) / 2, given,
                                    target);
            } else {
                return binarySearch(numbers, (max + min) / 2, max, given,
                                    target);
            }
        } else {
            return min;
        }
    }

    int pos = -1;
    vector<int> twoSum(vector<int> &numbers, int target) {
        // numbers can't be empty since it is said there always is a solution!
        int size = numbers.size();
        int result = -1;
        // replace with another binarySearch if this works (?) --> it obviously
        // will not work§
        for (int i = 0; i != numbers.size() - 1; i++) {
            // Min can be changed from 0 to i to reduce the number of ops
            // since if pair (i, j) was found where i <= j
            // it would've been found earlier for fixed i while searching j
            result = binarySearch(numbers, i + 1, size, numbers[i], target);
            if (numbers[i] + numbers[result] == target) {
                return {i + 1, result + 1};
            }
        }
        return {-1, -1};
    }
};