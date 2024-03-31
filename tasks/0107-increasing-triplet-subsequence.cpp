class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int min_first = INT_MAX;
        int min_second = INT_MAX;
        for (auto &elem : nums) {
            if (elem <= min_first) {
                min_first = elem;
            } else if (elem <= min_second) {
                min_second = elem;
            } else {
                return true;
            }
        }
        return false;
    }
};