#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxOperations(vector<int> &nums, int k) {
        unordered_map<int, int> elems;
        for (auto &elem : nums) {
            if (elems[k - elem] != 0) {
                elems[k - elem]--;
            } else {
                elems[elem]++;
            }
        }   // O(n)
        int result = 0;
        for (auto &elem : elems) {   // O(n) --> max
            // cout << elem.second;
            result += elem.second;
        }
        return (nums.size() - result) / 2;
        // O(n) memory
    }

    // NOTE:
    // Can be solved with two pointers
    // by first sorting the array, then iterating towards middle
    // Difficulty comparison:
    // [O(n), O(n)] --> [O(n*log(n)), O(1)]
};