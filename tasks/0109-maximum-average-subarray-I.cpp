class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        double temp_result = 0;
        for (int i = 0; i < k; i++) {
            temp_result += nums[i];
        }
        double max_result = temp_result / k;
        // cout << max_result << "\n";
        int i = k;
        while (i < nums.size()) {
            temp_result -= nums[i - k];
            temp_result += nums[i];
            double cur = temp_result / k;
            // cout << cur << "\n";
            max_result = max(max_result, cur);
            i++;
        }
        return max_result;
    }
};