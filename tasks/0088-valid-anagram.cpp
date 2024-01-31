class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> counter;
        for (int i = 0; i < s.size(); i++) {
            counter[s[i]]++;
            counter[t[i]]--;
        }
        for (auto &elem : counter) {
            if (elem.second != 0) {
                return false;
            }
        }
        return true;
    }
};