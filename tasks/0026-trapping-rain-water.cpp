#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int trap(vector<int> &height) {
        if (height.size() <= 1) {
            return 0;
        }
        int current_max = height[0];
        int current_idx = 0;
        vector<int> local_maxes = {0};
        for (int i = 1; i != height.size(); i++) {
            if (height[i] >= current_max) {
                current_idx = i;
                current_max = height[i];
                local_maxes.push_back(current_idx);
            }
        }
        if (local_maxes.empty()) {
            return 0;
        }
        vector<int> local_maxes_2 = {static_cast<int>(height.size()) - 1};
        int global_max = local_maxes.back();
        if (local_maxes.back() != height.size() - 1) {
            current_max = height[height.size() - 1];
            current_idx = height.size() - 1;
            for (int i = height.size() - 1; i != global_max - 1; i--) {
                if (height[i] >= current_max) {
                    current_max = height[i];
                    current_idx = i;
                    local_maxes_2.push_back(current_idx);
                }
            }
        }
        int result = 0;
        for (int i = 1; i < local_maxes.size(); i++) {
            auto water_level =
                min(height[local_maxes[i - 1]], height[local_maxes[i]]);
            // cout << "New water level!\n";
            for (int j = local_maxes[i - 1] + 1; j < local_maxes[i]; j++) {
                // cout << "j = " << j << "\n";
                // cout << "water_lvl = " << water_level
                //      << ", height = " << height[j] << "\n";
                if (height[j] < water_level) {
                    result += (water_level - height[j]);
                }
            }
        }
        /*
        cout << "Printing local_maxes\n";
        for (auto &elem : local_maxes) {
            cout << elem << "; ";
        }
        cout << "\n";
        */
        for (int i = local_maxes_2.size() - 1; i > 0; i--) {
            auto water_level =
                min(height[local_maxes_2[i - 1]], height[local_maxes_2[i]]);
            for (int j = local_maxes_2[i] + 1; j < local_maxes_2[i - 1]; j++) {
                if (height[j] < water_level) {
                    result += (water_level - height[j]);
                }
            }
        }
        /*
        cout << "Printing local_maxes_2\n";
        for (auto &elem : local_maxes_2) {
            cout << elem << "; ";
        }
        cout << "\n";]
        */
        return result;
    }
};

int
main() {
    Solution solution;
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> heights = {4, 2, 0, 3, 2, 5};
    //      1
    // 1****1
    // 1**1*1
    // 11*111
    // 11*111
    cout << solution.trap(heights);
}

// Code draft [wrong idea]
/*
class Solution {
  public:
    int trap(vector<int> &height) {
        if (height.size() <= 1) {
            return 0;
        }
        vector<vector<int>> changes;
        vector<int> current = {0, 1, (height[1] <= height[0])};
        int result = 0;
        // {start, end, inc=0/dec=1}
        for (int i = 1; i != height.size(); i++) {
            if (height[i] < height[i - 1]) {
                cout << "DEBUG | The heights is decreasing!\n";
                if (current[2] == 1) {
                    cout << "Same pace as previous step!\n";
                    current[1] = i;
                } else {
                    cout << "Changing pace!\n";
                    changes.push_back(current);
                    current = {i - 1, i, 1};
                }
            } else if (height[i] > height[i - 1]) {
                cout << "DEBUG | The heights is increasing!\n";
                if (current[2] == 0) {
                    cout << "Same pace as previous step!\n";
                    current[1] = i;
                } else {
                    cout << "Changing pace!\n";
                    changes.push_back(current);
                    current = {i - 1, i, 0};
                }
            } else {
                cout << "DEBUG | The heights is equal!\n";
                current[1] = i;
            }
        }
        if (changes.size() <= 1) {
            return result;
        }

        cout << "Printing changes vector\n";
        for (auto &elem : changes) {
            for (auto &num : elem) {
                cout << num << " ";
            }
            cout << "\n";
        }

        for (int i = 1; i != changes.size(); i++) {
            if (changes[i - 1][2] == 1) {
                cout << "DEBUG | Found some water!\n";
                auto idx_decr = changes[i - 1][0];
                auto max_height_decr = height[idx_decr];
                auto idx_incr = changes[i][1];
                auto max_height_incr = height[idx_incr];
                auto water_height = min(max_height_decr, max_height_incr);
                cout << "DEBUG | Decr->Incr on [" << idx_decr << "," << idx_incr
                     << "]!\n";
                cout << "DEBUG | Height changes from " << max_height_decr
                     << " to " << max_height_incr << "\n";
                for (int j = idx_decr + 1; j < idx_incr; j++) {
                    cout << "DEBUG | On idx = " << j
                         << " current water = " << height[j] << "\n";
                    if (height[j] < water_height) {
                        result += (water_height - height[j]);
                    }
                }
            }
        }
        return result;
    }
};
*/