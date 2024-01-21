#include <vector>

using namespace std;

class Solution {
  private:
    vector<vector<bool>> visited;
    int m;
    int n;

  public:
    void dfs(vector<vector<char>> &grid, int idx_i, int idx_j) {
        visited[idx_i][idx_j] = 1;
        // grid[idx_i][idx_j] = 'X';
        /*
        if (idx_i < min_max[0]) {
            min_max[0] = idx_i;
        }
        if (idx_j < min_max[1]) {
            min_max[1] = idx_j;
        }
        if (idx_i > min_max[2]) {
            min_max[2] = idx_i;
        }
        if (idx_j > min_max[3]) {
            min_max[3] = idx_j;
        }
        */
        if (idx_i < m - 1 && grid[idx_i + 1][idx_j] == 'O' &&
            !visited[idx_i + 1][idx_j]) {
            dfs(grid, idx_i + 1, idx_j);
        }
        if (idx_j < n - 1 && grid[idx_i][idx_j + 1] == 'O' &&
            !visited[idx_i][idx_j + 1]) {
            dfs(grid, idx_i, idx_j + 1);
        }
        if (idx_j > 0 && grid[idx_i][idx_j - 1] == 'O' &&
            !visited[idx_i][idx_j - 1]) {
            dfs(grid, idx_i, idx_j - 1);
        }
        if (idx_i > 0 && grid[idx_i - 1][idx_j] == 'O' &&
            !visited[idx_i - 1][idx_j]) {
            dfs(grid, idx_i - 1, idx_j);
        }
    }

    /*
    void dfs_paint(vector<vector<char>> &grid, int idx_i, int idx_j) {
        visited[idx_i][idx_j] = 0;
        grid[idx_i][idx_j] = 'X';
        if (idx_i < m - 1 && grid[idx_i + 1][idx_j] == 'O' &&
            visited[idx_i + 1][idx_j]) {
            dfs(grid, idx_i + 1, idx_j);
        }
        if (idx_j < n - 1 && grid[idx_i][idx_j + 1] == 'O' &&
            visited[idx_i][idx_j + 1]) {
            dfs(grid, idx_i, idx_j + 1);
        }
        if (idx_j > 0 && grid[idx_i][idx_j - 1] == 'O' &&
            visited[idx_i][idx_j - 1]) {
            dfs(grid, idx_i, idx_j - 1);
        }
        if (idx_i > 0 && grid[idx_i - 1][idx_j] == 'O' &&
            visited[idx_i - 1][idx_j]) {
            dfs(grid, idx_i - 1, idx_j);
        }
    }
    */

    void solve(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();
        visited.resize(m);
        for (auto &elem : visited) {
            elem.resize(n, 0);
        }
        vector<int> var_i = {0};
        if (m > 1) {
            var_i.push_back(m - 1);
        }
        vector<int> var_j = {0};
        if (n > 1) {
            var_j.push_back(n - 1);
        }
        for (int &i : var_i) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'O' && !visited[i][j]) {
                    dfs(grid, i, j);
                }
            }
        }
        for (int i = 1; i < m - 1; i++) {
            for (int &j : var_j) {
                if (grid[i][j] == 'O' && !visited[i][j]) {
                    dfs(grid, i, j);
                }
            }
        }
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!visited[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};