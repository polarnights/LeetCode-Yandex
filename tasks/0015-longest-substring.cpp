#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int current_uneq = 0;
        int result = -1;
        unordered_map<char, int> counter;
        int start = 0;
        int end = 0;
        while (true) {
            while (current_uneq == 0) {
                if (end >= s.size()) {
                    return result;
                }
                counter[s[end]]++;
                if (counter[s[end]] == 2) {
                    current_uneq++;
                    cout << "DEBUG 4 | not upd. result since current_uneq = "
                         << current_uneq << ", adding symbol = " << s[end]
                         << " on end =" << end << "\n";
                } else {
                    result = max(result, end - start + 1);
                    cout << "DEBUG 3| end - start = " << end - start
                         << "; end = " << end << ", start = " << start << "\n";
                    end++;
                }

                cout << "DEBUG 1| end = " << end << ", start = " << start
                     << "; current_uneq = " << current_uneq
                     << ", current result =" << result << "\n";
            }
            while (current_uneq != 0) {
                if (start >= s.size()) {
                    return result;
                }
                counter[s[start]]--;
                if (counter[s[start]] == 1) {
                    current_uneq--;
                }
                start++;

                cout << "DEBUG 2| end = " << end << ", start = " << start
                     << "; current_uneq = " << current_uneq
                     << ", current result =" << result << "\n";
            }
            end++;
        }
    }
};

int
main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("pwwkew") << "\n";
}

// Not a very optimized solution though =(