#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        // - 1 <= s.length <= 10^4
        // - There is at least one word in s
        int i = 0;
        int j = s.size() - 1;
        string result = "";
        vector<pair<int, int>> words_1;
        vector<pair<int, int>> words_2;
        while (i <= j) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            while (j >= 0 && s[j] == ' ') {
                j--;
            }
            // cout << "1\n";
            // cout << i << " " << j << "\n";
            if (i > j) {
                break;
            }
            // cout << "2\n";
            auto saved_i = i;
            auto saved_j = j;
            while (i + 1 < s.size() && s[i + 1] != ' ') {
                i++;
            }
            while (j - 1 >= 0 && s[j - 1] != ' ') {
                j--;
            }
            if (saved_j == i) {
                // cout << "here\n";
                words_1.push_back({saved_i, saved_j});
                break;
            } else {
                words_2.push_back({saved_i, i});
                words_1.push_back({j, saved_j});
                i++;
                j--;
            }
        }
        for (int i = 0; i < words_1.size(); i++) {
            result += s.substr(words_1[i].first,
                               words_1[i].second - words_1[i].first + 1);
            if (i != words_1.size() - 1 || words_2.size() != 0) {
                result += ' ';
            }
        }
        for (int i = words_2.size() - 1; i >= 0; i--) {
            result += s.substr(words_2[i].first,
                               words_2[i].second - words_2[i].first + 1);
            if (i != 0) {
                result += ' ';
            }
        }
        return result;
    }
};