#include <cstdint>

class Solution {
  public:
    double myPow(double x, int n) {
        double result = 1;
        if (n == 0) {
            return 1;
        }
        int64_t new_n = n;
        if (n < 0) {
            new_n *= -1;
            x = 1 / x;
            // cout << x << "\n";
        }
        while (new_n > 0) {
            if (new_n % 2 == 1) {
                result *= x;
            }
            x *= x;
            new_n /= 2;
        }
        return result;
    }
};