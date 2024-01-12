#include <vector>

using namespace std;

class Solution {
  public:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    void rotate(vector<int> &nums, int k) {
        if (nums.empty()) {
            return;
        }
        int gcd_res = gcd(nums.size(), k);
        int saved;
        int current;
        int tmp;
        for (int i = 0; i < gcd_res; i++) {
            saved = nums[i];
            current = (i + k) % nums.size();
            tmp = -1;
            while (current != i) {
                tmp = nums[current];
                nums[current] = saved;
                saved = tmp;
                current = (current + k) % nums.size();
            }
            nums[current] = saved;
        }
    }
};