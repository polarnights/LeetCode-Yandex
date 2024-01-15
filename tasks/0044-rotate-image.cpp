#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int size = matrix.size();
        int cur = -1;
        int tmp_i, tmp_j;
        for (int i = 0; i < (size + 1) / 2; i++) {
            for (int j = 0; j < size / 2; j++) {
                tmp_i = i;
                tmp_j = j;
                cur = matrix[tmp_i][tmp_j];
                for (int t = 0; t < 4; t++) {
                    auto tmp = matrix[tmp_j][size - 1 - tmp_i];
                    matrix[tmp_j][size - 1 - tmp_i] = cur;
                    cur = tmp;
                    tmp = tmp_j;
                    tmp_j = size - 1 - tmp_i;
                    tmp_i = tmp;
                }
            }
        }
    }
};