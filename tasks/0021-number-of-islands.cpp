#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<vector<bool>> visited;
    int n;
    int m;

  public:
    void dfs(vector<vector<char>> &grid, int idx_i, int idx_j) {
        visited[idx_i][idx_j] = 1;
        if (idx_i < m - 1 && grid[idx_i + 1][idx_j] == '1' &&
            !visited[idx_i + 1][idx_j]) {
            dfs(grid, idx_i + 1, idx_j);
        }
        if (idx_j < n - 1 && grid[idx_i][idx_j + 1] == '1' &&
            !visited[idx_i][idx_j + 1]) {
            dfs(grid, idx_i, idx_j + 1);
        }
        if (idx_j > 0 && grid[idx_i][idx_j - 1] == '1' &&
            !visited[idx_i][idx_j - 1]) {
            dfs(grid, idx_i, idx_j - 1);
        }
        if (idx_i > 0 && grid[idx_i - 1][idx_j] == '1' &&
            !visited[idx_i - 1][idx_j]) {
            dfs(grid, idx_i - 1, idx_j);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }   // 1 <= m, n according to the task
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        visited.resize(m);
        for (auto &elem : visited) {
            elem.resize(n, 0);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << "DEBUG | i = " << i << ", j = " << j
                //      << ", grid[i, j] = " << grid[i][j]
                //      << ", visited[i, j] == " << visited[i][j] << '\n';
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // cout << "DEBUG | DFS started\n";
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};

int
main() {
    Solution solution;
    vector<vector<char>> test_case{{'1', '1', '0', '0', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '1', '0', '0'},
                                   {'0', '0', '0', '1', '1'}};
    cout << solution.numIslands(test_case) << "\n";
}