using namespace std;

#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Fix the case where every number is 1
        int prev_seq_length = -1, current_seq_length = 0;
        // TODO: Figure out why this works slower in runtime than in separate lines
        int result = 0;
        for (auto& elem: nums) {
            if (elem == 1) {
                current_seq_length++;
            } else {
                if (prev_seq_length + current_seq_length > result) {
                    result = prev_seq_length + current_seq_length;
                }
                prev_seq_length = current_seq_length;
                current_seq_length = 0;
            }
        }
        if (prev_seq_length + current_seq_length > result) {
            result = prev_seq_length + current_seq_length;
        }
        return result;
    }
};