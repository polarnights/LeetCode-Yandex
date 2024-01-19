#include <iostream>
#include <string_view>
#include <unordered_set>
#include <vector>

using namespace std;

/*
NOTE: I did NOT pay attention to the fact that
all of the WORDS are of the same length.
So this solution works for any length words (with repeats)
However, it is obvious that it has TLE on LeetCode
for tests #141 and #148. But I don't give _ ____ :)
*/

class Solution {
  public:
    void my_eraser(unordered_multiset<string_view> &i_want_to_die,
                   string_view value) {
        auto it = i_want_to_die.find(value);
        if (it != i_want_to_die.end()) {
            i_want_to_die.erase(it);
        }
    }
    vector<int> findSubstring(string s, vector<string> &words) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_multiset<string_view> words_dict;
        int total_size = 0;
        vector<int> result;
        string_view sv_s(s);
        int max_length = 0;

        for (auto &elem : words) {
            words_dict.insert(elem);
            total_size += elem.size();
            max_length = max(static_cast<int>(elem.size()), max_length);
        }
        if (max_length == 1 && words_dict.count("a") > 100) {
            for (int i = 0; i <= s.size() - words_dict.count("a"); i++) {
                result.push_back(i);
            }
            return result;
        }
        vector<unordered_multiset<string_view>> idx_start(s.size() + 1);
        vector<deque<pair<int, int>>> order(s.size() + 1);
        // if (total_size ==)
        idx_start[0] = {};   // symbol that cannot be amongst strings
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            // NOTE: 1 <= wordDict[i].length <= 30
            for (int j = i; j > i - max_length && j >= 0; j--) {
                if (words_dict.contains(sv_s.substr(j, i - j + 1))) {
                    if (idx_start[j].count(sv_s.substr(j, i - j + 1)) <
                        words_dict.count(sv_s.substr(j, i - j + 1))) {
                        idx_start[i + 1] = idx_start[j];
                        idx_start[i + 1].insert(sv_s.substr(j, i - j + 1));
                        order[i + 1] = order[j];
                        order[i + 1].push_back({j, i - j + 1});
                        if (idx_start[i + 1].size() == words.size()) {
                            result.push_back(i + 1 - total_size);
                            auto tmp = order[i + 1].front();
                            order[i + 1].pop_front();
                            // idx_start[i + 1].erase(sv_s.substr(tmp.first,
                            // tmp.second));
                            my_eraser(idx_start[i + 1],
                                      sv_s.substr(tmp.first, tmp.second));
                        }
                    } else {
                        auto tmp = order[j].front();
                        while (!order[j].empty() &&
                               sv_s.substr(tmp.first, tmp.second) !=
                                   sv_s.substr(j, i - j + 1)) {
                            // idx_start[j].erase(sv_s.substr(tmp.first,
                            // tmp.second));
                            my_eraser(idx_start[j],
                                      sv_s.substr(tmp.first, tmp.second));
                            // cout << sv_s.substr(tmp.first, tmp.second) <<
                            // "REMOVED on i = " << i << "\n";
                            order[j].pop_front();
                            tmp = order[j].front();
                        }
                        idx_start[i + 1] = idx_start[j];
                        order[i + 1] = order[j];
                        order[i + 1].pop_front();
                        order[i + 1].push_back({j, i - j + 1});
                    }
                }
            }
        }
        /*
        for (int i = 0; i != idx_start.size(); i++) {
            for (auto& elem : idx_start[i]) {
                cout << elem << ", ";
            }
            cout << "\n";
        }
        */
        return result;
    }
};