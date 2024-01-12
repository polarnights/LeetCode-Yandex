class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int current_element;
        int current_count = 0;
        for (auto &elem : nums) {
            if (current_count == 0) {
                current_element = elem;
            }
            if (current_element == elem) {
                current_count++;
            } else {
                current_count--;
            }
        }
        return current_element;
    }
};