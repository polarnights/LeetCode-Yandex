#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int m_r = m - 1, n_r = n - 1;
        int m_l = 0, n_l = 0;
        vector<int> result(m * n);
        int count = 0;
        int i = 0;
        int j = 0;
        int direction = 1;
        while (count != m * n) {
            // 1 = Right
            // 2 = Down
            // 3 = Left
            // 4 = Up
            result[count] = matrix[i][j];
            count++;
            switch (direction) {
            case 1:
                if (j == n_r) {
                    m_l++;
                    direction = 2;
                    i++;
                } else {
                    j++;
                }
                break;
            case 2:
                if (i == m_r) {
                    n_r--;
                    direction = 3;
                    j--;
                } else {
                    i++;
                }
                break;
            case 3:
                if (j == n_l) {
                    m_r--;
                    direction = 4;
                    i--;
                } else {
                    j--;
                }
                break;
            case 4:
                if (i == m_l) {
                    n_l++;
                    direction = 1;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return result;
    }
};