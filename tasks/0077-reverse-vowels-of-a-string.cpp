#include <string>

using namespace std;

class Solution {
  public:
    bool isVowel(char ch) {
        if (!isalpha(ch)) {
            return false;
        }
        ch = tolower(ch);
        // cout << ch << "\n";
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        // string result = s;
        while (i < j) {
            while (i < s.size() && !isVowel(s[i])) {
                i++;
            }
            while (j >= 0 && !isVowel(s[j])) {
                j--;
            }
            if (i >= s.size() || j < 0 || i >= j) {
                return s;
            }
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};