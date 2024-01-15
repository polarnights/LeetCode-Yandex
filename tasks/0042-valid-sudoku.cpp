#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    for (int t = 0; t < 9; t++) {
                        if (t != j && board[i][t] == board[i][j]) {
                            return false;
                        }
                        if (t != i && board[t][j] == board[i][j]) {
                            return false;
                        }
                    }
                }
            }
        }
        set<int> check_3x3;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                check_3x3.clear();
                for (int box_i = 0; box_i < 3; box_i++) {
                    for (int box_j = 0; box_j < 3; box_j++) {
                        if (board[i + box_i][j + box_j] != '.') {
                            if (check_3x3.contains(
                                    board[i + box_i][j + box_j])) {
                                return false;
                            }
                            check_3x3.insert(board[i + box_i][j + box_j]);
                        }
                    }
                }
            }
        }
        return true;
    }
};