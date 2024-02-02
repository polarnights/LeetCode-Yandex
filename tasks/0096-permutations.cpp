class Solution {
  private:
    vector<vector<int>> result;

  public:
    void makePermutation(vector<int> &nums, deque<int> &idxes,
                         vector<int> &current) {
        if (idxes.size() == 0) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < idxes.size(); i++) {
            auto elem = idxes.front();
            idxes.pop_front();
            current.push_back(nums[elem]);
            makePermutation(nums, idxes, current);
            current.pop_back();
            idxes.push_back(elem);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        // vector<vector<int>> result;
        deque<int> idxes;
        for (int i = 0; i < nums.size(); i++) {
            idxes.push_back(i);
        }
        vector<int> current = {};
        makePermutation(nums, idxes, current);
        return result;
    }
};