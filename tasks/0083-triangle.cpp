#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> result;
        // result.reserve(triangle.size());
        int i = 0;
        while (i <= triangle.size() - 1) {
            result.push_back(0);
            if (i > 0) {
                result.back() = result[result.size() - 2] + triangle[i].back();
            }

            for (int j = i - 1; j >= 1; j--) {
                result[j] = triangle[i][j] + min(result[j], result[j - 1]);
            }
            result[0] += triangle[i][0];
            i++;
        }

        int min_elem = INT_MAX;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] < min_elem) {
                min_elem = result[i];
            }
        }
        return min_elem;
    }
};