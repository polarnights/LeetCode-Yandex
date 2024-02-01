class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int start_i = 0;
        int end_i = matrix.size();
        int mid;
        while (end_i - start_i > 1) {
            // cout << "1\n";
            // cout << "end = " << end_i << " | start = " << start_i << "\n";
            mid = (start_i + end_i) / 2;
            if (matrix[mid][0] > target) {
                // cout << "1-1\n";
                end_i = mid;
            } else if (matrix[mid].back() < target) {
                // cout << "1-2\n";
                start_i = mid;
            } else {
                // cout << "1-3\n";
                start_i = mid;
                break;
            }
        }
        int row = start_i;
        // cout << "row = " << row << "\n";
        start_i = 0;
        end_i = matrix[0].size();
        while (end_i - start_i > 1) {
            // cout << "2\n";
            mid = (end_i + start_i) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start_i = mid;
            } else {
                end_i = mid;
            }
        }
        // Special for matrix[i].size() == 0
        if (matrix[row][start_i] == target) {
            return true;
        }
        return false;
    }
};