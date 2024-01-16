#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> banned_i;
        unordered_set<int> banned_j;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    banned_i.insert(i);
                    banned_j.insert(j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (banned_i.contains(i) || banned_j.contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};