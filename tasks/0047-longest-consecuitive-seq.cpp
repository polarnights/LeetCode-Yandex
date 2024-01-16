#include <unordered_map>
#include <vector>

using namespace std;

// Runtime complexity:
// O(n) : [3 * n -> best case, 4 * n -> worst case]
// n -> prev_elem setup
// n -> find result for every elem from nums BY:
// 1...n -> going from current element to lowest consecutive number
// n [TOTAL] -> always change every of n elements in prev_elem to INT_MIN

// Memory complexity:
// O(n) : n + eps
// Only initialize prev_elem vector, it's size = n

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> prev_elem;
        for (auto &elem : nums) {
            if (prev_elem.contains(elem)) {
                continue;
            }
            prev_elem[elem] = INT_MIN;
            if (prev_elem.contains(elem - 1)) {
                prev_elem[elem] = elem - 1;
            }
            if (prev_elem.contains(elem + 1)) {
                prev_elem[elem + 1] = elem;
            }
        }
        int result = 0;
        int temp_result, current;
        for (int i = 0; i < nums.size(); i++) {
            current = nums[i];
            while (prev_elem[current] != INT_MIN) {
                current = prev_elem[current];
            }
            temp_result = 1;
            while (prev_elem.contains(current + 1) &&
                   prev_elem[current + 1] != INT_MIN) {
                prev_elem[current] = INT_MIN;
                current++;
                temp_result++;
            }
            result = max(temp_result, result);
        }
        return result;
    }
};

// Turned out my approach is excessively complicated
// This is some random solution from LeetCode
// It has the same idea as this one, however only set is used and solution works
// well

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for(int num : nums){
            if(set.find(num-1) == set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while(set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence,
currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};
*/