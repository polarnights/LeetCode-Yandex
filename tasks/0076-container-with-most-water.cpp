#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int prev = min(height[i], height[j]) * (j - i);
        while (i < j) {
            if (height[i] > height[j]) {
                auto tmp = min(height[i], height[j]) * (j - i);
                if (tmp > prev) {
                    prev = tmp;
                }
                j--;
            } else {
                auto tmp = min(height[i], height[j]) * (j - i);
                if (tmp > prev) {
                    prev = tmp;
                }
                i++;
            }
        }
        return prev;
    }
};