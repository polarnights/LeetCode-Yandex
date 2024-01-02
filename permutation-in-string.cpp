#include <iostream>
#include <string>
#include <unordered_map>
#include <format>

using namespace std;

class Solution {
public:
    unordered_map<char, int> diff_counter;

    Solution() = default;
    bool checkInclusion(string s1, string s2) {
        for (char symbol : s1) {
            diff_counter[symbol]--;
        }
        if (s1.size() > s2.size()) {
            return false;
        }
        for (size_t i = 0; i < s1.size(); i++) {
            diff_counter[s2[i]]++;
            cout << "(!) DEBUG | on " <<  i << "th iteration | diff_counter[" << s2[i] << "] = " << diff_counter[s2[i]] << "\n";
            if (diff_counter[s2[i]] == 0) {
                diff_counter.erase(s2[i]);
            }
        }
        for (size_t i = s1.size(); i < s2.size(); i++) {
            if (diff_counter.empty()) {
                return true;
            }
            char elem_to_decrease = s2[i - s1.size()];
            diff_counter[elem_to_decrease]--;
            cout << "DEBUG | on " <<  i << "th iteration | diff_counter[" << elem_to_decrease << "] = " << diff_counter[elem_to_decrease] << "\n";
            if (diff_counter[elem_to_decrease] == 0) {
                diff_counter.erase(elem_to_decrease);
            }
            diff_counter[s2[i]]++;
            cout << "DEBUG | on " <<  i << "th iteration | diff_counter[" << s2[i] << "] = " << diff_counter[s2[i]] << "\n";
            if (diff_counter[s2[i]] == 0) {
                diff_counter.erase(s2[i]);
            }
        }
        if (diff_counter.empty()) {
            return true;
        }
        return false;
    }

     ~Solution() = default;
};

int main() {
    Solution solution;
    cout << solution.checkInclusion("ab", "eidbakoo") << "\n";
}