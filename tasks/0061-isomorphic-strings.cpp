#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> exchange;
        unordered_map<char, char> exchange2;
        for (int i = 0; i != s.size(); i++) {
            if (!exchange.contains(t[i]) && !exchange2.contains(s[i])) {
                exchange[t[i]] = s[i];
                exchange2[s[i]] = t[i];
            } else {
                if (exchange[t[i]] != s[i] || exchange2[s[i]] != t[i]) {
                    cout << "!!!\n";
                    return false;
                }
            }
        }
        return true;
    }
};