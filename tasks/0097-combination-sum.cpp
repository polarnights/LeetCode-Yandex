class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // cout << candidates[0] << "\n";
        deque<tuple<int, int, vector<int>>> order;
        order.push_back({0, 0, {}});
        vector<vector<int>> result;
        while (!order.empty()) {
            auto cur = get<2>(order.front());
            auto sum = get<0>(order.front());
            auto idx_start = get<1>(order.front());
            order.pop_front();
            int i = idx_start;
            while (i < candidates.size() && candidates[i] + sum <= target) {
                cur.push_back(candidates[i]);
                if (sum + candidates[i] == target) {
                    result.push_back(cur);
                } else {
                    order.push_back({sum + candidates[i], i, cur});
                }
                i++;
                cur.pop_back();
            }
        }
        /*
        for (auto& elem: order) {
            cout << get<0>(elem) << " " << get<1>(elem) << "\n";
            for (auto x : get<2>(elem)) {
                cout << x << " ";
            }
            cout << "\n------\n";
            if (get<0>(elem) == target) {
                cout << "GOOD ELEM UP \n";
                result.push_back(get<2>(elem));
            }
        }
        */
        return result;
    }
};