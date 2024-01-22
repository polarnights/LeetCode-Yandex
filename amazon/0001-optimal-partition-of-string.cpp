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