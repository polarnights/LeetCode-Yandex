#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // TODO: Should we pass string by &?
  public:
    pair<int, int> solve(string str) {
        unordered_map<char, int> count_chars;
        int alphabet_size = 0;
        int current_alphabet_size = 0;
        int start = -1, end = 0;
        int saved_start = -1, saved_end = -1, saved_diff = INT_MAX;
        for (char elem : str) {
            count_chars[elem]++;
            if (count_chars[elem] == 1) {
                alphabet_size++;
            }
        }
        count_chars.clear();
        while (end < str.size()) {
            count_chars[str[end]]++;
            if (count_chars[str[end]] == 1) {
                current_alphabet_size++;
            }
            if (current_alphabet_size == alphabet_size) {
                cout << "DEBUG | Dict sizes are equal on start = " << start
                     << ", end = " << end << "\n";
                cout << "DEBUG | Sizes are == " << current_alphabet_size
                     << "\n";
                while (current_alphabet_size == alphabet_size &&
                       count_chars[str[start + 1]] > 1) {
                    start++;
                    cout << "DEBUG | Decreased count[" << str[start]
                         << "] from " << count_chars[str[start]] << "(-= 1)\n";
                    count_chars[str[start]]--;
                }
                if (end - start < saved_diff) {
                    cout << "DEBUG | Change diff from saved_diff = "
                         << saved_diff << " to " << end - start << "\n";
                    saved_diff = end - start;
                    saved_start = start;
                    saved_end = end;
                }
                start++;
                count_chars[str[start]]--;
                if (count_chars[str[start]] == 0) {
                    current_alphabet_size--;
                }
            }
            end++;
        }
        return {saved_start + 1, saved_end};
    }
};

int
main() {
    Solution solution;
    auto result = solution.solve("aaaaaaaaaa");
    // auto result = solution.solve("abccccddddaddabddc");
    //                            -------7
    //                                         -----5
    cout << result.first << " " << result.second << "\n";
}