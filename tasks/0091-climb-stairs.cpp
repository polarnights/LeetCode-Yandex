class Solution {
  public:
    int climbStairs(int n) {
        /*
        Note: can be optimized by storing only 2 prev values
        Since it is stated that n <= 45 it is basically useless to do that
        Also one can hardcode a dict which contains all solution values for each
        n <= 45
        */
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;   // 1-st
        dp[1] = 2;   // 2-nd
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};