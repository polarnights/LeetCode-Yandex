#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<char, int> counter;
        unordered_map<size_t, vector<int>> idxes;
        vector<vector<string>> result;
        string temp_str;
        for (int i = 0; i != strs.size(); i++) {
            temp_str = "";
            for (auto &elem : strs[i]) {
                counter[elem]++;   // O(len(strs))
            }
            for (auto &elem :
                 counter) {   // O(1) = limited by available symbols in str
                temp_str += elem.first;
                temp_str += to_string(elem.second);
            }
            // TODO: Figure out what this syntax means
            auto hash_str = hash<string>{}(temp_str);
            idxes[hash_str].push_back(i);
            counter.clear();   // O(size(counter)) = O(1) = limited by available
                               // symbols in str
        }
        result.reserve(idxes.size());
        for (auto &elem : idxes) {
            result.push_back({});
            for (auto &idx : elem.second) {
                result.back().push_back(strs[idx]);
            }
        }
        return result;
    }
};