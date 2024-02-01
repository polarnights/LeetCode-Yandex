class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        int i = 0;
        int j = 0;
        while (true) {
            if (j >= nums.size()) {
                return false;
            }
            if (j - i <= k) {
                counter[nums[j]]++;
                if (counter[nums[j]] == 2) {
                    return true;
                }
                j++;
            } else {
                counter[nums[i]]--;
                i++;
            }
        }
    }
};