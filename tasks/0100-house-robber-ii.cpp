class Solution {
  private:
    vector<int> dp;

  public:
    int rob_helper(vector<int> &nums) {
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] - nums[i - 1] + nums[i], dp[i - 2] + nums[i]);
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        dp.resize(nums.size());
        int saved_last = nums.back();
        nums.back() = 0;
        int cur_result = rob_helper(nums);
        nums.back() = saved_last;
        nums[0] = 0;
        return max(cur_result, rob_helper(nums));
    }
};