#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int partitionString(string s) {
        int result = 0;
        int i = 0;
        unordered_set<char> current_alphabet;
        for (int i = 0; i < s.size(); i++) {
            if (!current_alphabet.contains(s[i])) {
                current_alphabet.insert(s[i]);
            } else {
                current_alphabet.clear();
                current_alphabet.insert(s[i]);
                result++;
            }
        }
        if (!current_alphabet.empty()) {
            result++;
        }
        return result;
    }
};

// Correct solution
// TODO: Verify my explanation of this (most optimal) solution:
// v = 2^0 * x_0 + 2^1 * x_1 + ... + 2^25 * x_25
// n = 26 letters in the alphabet
// if we had already encountered some char CUR, we need to check
// (CUR - 'a')th bit. If it is equal to 1, we set v = 0;
// Otherwise, we increment (CUR - 'a')th bit (v += 2^(...))

/*
class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        int v = 0;
        for (char c : s) {
            int i = c - 'a';
            if ((v >> i) & 1) {
                v = 0;
                ++ans;
            }
            v |= 1 << i;
        }
        return ans;
    }
};
*/