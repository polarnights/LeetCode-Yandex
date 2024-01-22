#include <string>

using namespace std;

class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            while (j < t.size() && t[j] != s[i]) {
                j++;
            }
            if (j == t.size()) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        if (i == s.size()) {
            return true;
        }
        return false;
    }
};