#include <vector>

using namespace std;

class Solution {
  public:
    // Simply fill from the highest to lowest
    // to avoid issues with replacing elems
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int first = m - 1;
        int second = n - 1;
        int idx = m + n - 1;
        while (first >= 0 && second >= 0) {
            if (nums1[first] > nums2[second]) {
                nums1[idx] = nums1[first];
                first--;
            } else {
                nums1[idx] = nums2[second];
                second--;
            }
            idx--;
        }
        while (second >= 0) {
            nums1[idx] = nums2[second];
            idx--;
            second--;
        }
    }
};