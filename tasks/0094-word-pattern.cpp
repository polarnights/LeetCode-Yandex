class Solution {
  public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pattern_check;
        unordered_set<string> strings;
        size_t cur = s.find(' ', 0);
        size_t prev = 0;
        int i = 0;
        while (cur != string::npos) {
            // cout << "i = " << i << " | " << s.substr(prev, cur - prev) <<
            // "\n";
            if (i >= pattern.size()) {
                return false;
            }
            if (pattern_check.contains(pattern[i])) {
                if (pattern_check[pattern[i]] != s.substr(prev, cur - prev)) {
                    return false;
                }
            } else {
                auto tmp = s.substr(prev, cur - prev);
                if (strings.contains(tmp)) {
                    return false;
                }
                strings.insert(tmp);
                pattern_check[pattern[i]] = tmp;
            }
            prev = cur + 1;
            cur = s.find(' ', prev);
            i++;
        }
        if (i != pattern.size() - 1) {
            return false;
        }
        string tmp = s.substr(prev, s.size() - prev);
        if (pattern_check.contains(pattern[i])) {
            if (pattern_check[pattern[i]] != tmp) {
                return false;
            }
        } else {
            return !strings.contains(tmp);
        }
        return true;
    }
};