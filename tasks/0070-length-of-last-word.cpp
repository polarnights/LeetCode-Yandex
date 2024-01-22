#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        bool isWordNow = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                isWordNow = false;
            } else {
                if (!isWordNow) {
                    isWordNow = true;
                    counter = 0;
                }
                counter++;
            }
        }
        return counter;
    }
};