#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size(), n = board[0].size();
        vector<bool> saved_first(n, 0);
        vector<bool> saved_current(n);
        int count = 0;
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                count = 0;
                saved_current[j] = board[i][j];
                count += saved_first[j];   // 1 special
                if (i != m - 1) {
                    count += board[i + 1][j];   // 2
                }
                if (j != 0) {
                    count += saved_first[j - 1];     // 3 special
                    count += saved_current[j - 1];   // 4
                    if (i != m - 1) {
                        count += board[i + 1][j - 1];   // 5
                    }
                }
                if (j != n - 1) {
                    count += saved_first[j + 1];   // 6 special
                    count += board[i][j + 1];      // 7
                    if (i != m - 1) {
                        count += board[i + 1][j + 1];   // 8
                    }
                }
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        board[i][j] = 0;
                    }
                } else {
                    if (count == 3) {
                        board[i][j] = 1;
                    }
                }
            }
            // saved_first = saved_current;
            swap(saved_first, saved_current);
        }
    }
};

// Why does it use so much memory?