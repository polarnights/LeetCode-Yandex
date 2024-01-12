class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() < k) {
            // todo
        }
        int i = nums.size() - 1;
        auto next = i - k;
        auto saved = nums[i];
        auto prev = i;
        auto tmp = -1;
        while (prev != tmp) {
            while (next >= 0) {
                nums[next + k] = nums[next];
                next -= k;
            }
            tmp = nums.size() + next;
            if (tmp == prev) {
                break;
            } else {
                prev = tmp;
            }
            nums[tmp] = nums[next + k];
            next = tmp - k;
        }
    }
};

// Draft
// todo - soltuion is a circular graph (кольцо из индексов)