#include <string>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        int start = 0;
        int i = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[start]) {
                if (start == needle.size() - 1) {
                    return i - start;
                }
                start++;
                i++;
            } else {
                i -= start;
                i++;
                start = 0;
            }
        }
        return -1;
    }
};