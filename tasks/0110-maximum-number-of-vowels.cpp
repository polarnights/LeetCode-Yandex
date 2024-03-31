#include <string>

using namespace std;

class Solution {
  public:
    int vowelChecker(char s) {
        return (s == 'e' || s == 'a' || s == 'i' || s == 'u' || s == 'o');
    }
    int maxVowels(string s, int k) {
        int temp_result = 0;
        for (int i = 0; i < k; i++) {
            temp_result += vowelChecker(s[i]);
        }
        int max_result = temp_result;
        int i = k;
        while (i < s.size()) {
            temp_result -= vowelChecker(s[i - k]);
            temp_result += vowelChecker(s[i]);
            max_result = max(max_result, temp_result);
            i++;
        }
        return max_result;
    }
};