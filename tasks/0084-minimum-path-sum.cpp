#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<vector<int>> dp;
        dp.resize(grid.size());
        for (auto &elem : dp) {
            elem.resize(grid[0].size(), 0);
        }
        int i = 0, j = 0;
        dp[0][0] = grid[0][0];
        while (i + 1 < grid.size()) {
            dp[i + 1][0] = dp[i][0] + grid[i + 1][0];
            i++;
        }
        while (j + 1 < grid[0].size()) {
            dp[0][j + 1] = dp[0][j] + grid[0][j + 1];
            j++;
        }
        if (grid.size() == 1 || grid[0].size() == 1) {
            return dp[grid.size() - 1][grid[0].size() - 1];
        }
        int saved_i = 1, saved_j = 1;
        bool flag_i = false, flag_j = false;
        while (!(flag_i && flag_j)) {
            i = saved_i;
            j = saved_j;
            while (i < grid.size()) {
                dp[i][saved_j] = min(dp[i - 1][saved_j], dp[i][saved_j - 1]) +
                                 grid[i][saved_j];
                // cout << "dp[" << i << "][" << saved_j << "] = " <<
                // dp[i][saved_j] << "\n";
                i++;
            }
            j++;
            while (j < grid[0].size()) {
                dp[saved_i][j] = min(dp[saved_i][j - 1], dp[saved_i - 1][j]) +
                                 grid[saved_i][j];
                // cout << "dp[" << saved_i << "][" << j << "] = " <<
                // dp[saved_i][j] << "\n";
                j++;
            }
            if (saved_i < grid.size() - 1) {
                saved_i++;
            } else {
                flag_i = true;
            }
            if (saved_j < grid[0].size() - 1) {
                saved_j++;
            } else {
                flag_j = true;
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};