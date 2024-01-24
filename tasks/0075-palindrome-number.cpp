#include <iostream>

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int64_t i = 10;
        while (x / i > 0) {
            i *= 10;
        }
        i /= 10;
        while (x > 0 && i > 0) {
            // cout << "i = " << i << "(x/i)" =
            if (x / i != x % 10) {
                return false;
            }
            x -= (x / i) * i;
            x /= 10;
            i /= 100;
        }
        return true;
    }
};