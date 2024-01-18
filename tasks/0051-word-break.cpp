#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string_view> word_dict;
        string_view sv_s(s);
        for (auto &elem : wordDict) {
            word_dict.insert(elem);
        }
        vector<int> idx_start(s.size() + 1, INT_MIN);
        idx_start[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            // NOTE: 1 <= wordDict[i].length <= 20
            for (int j = i; j >= i - 20 && j >= 0; j--) {
                if (idx_start[j] != INT_MIN &&
                    word_dict.contains(sv_s.substr(j, i - j + 1))) {
                    /*
                    cout << "Found '" << sv_s.substr(j, i - j + 1) << "' on j =
                    " << j << " | size = " << i - j + 1 << "\n";
                    */
                    idx_start[i + 1] = i + 1;
                }
            }
        }
        /*
        int i = 0;
        for (auto& elem: idx_start) {
            cout << "i = " << i << " | elem = " << elem << "\n";
            i++;
        }
        */
        if (idx_start.back() == s.size()) {
            // cout << idx_start.back() << " | " << s.size() << "\n";
            return true;
        }
        return false;
    }
};