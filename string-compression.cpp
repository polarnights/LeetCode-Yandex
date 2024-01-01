#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> result = {};
        size_t chars_size = chars.size();
        int start = 0, count = 0;
        bool flag = true;
        while (flag) {
            while (start + count < chars_size && \
            chars[start + count] == chars[start]) {
                count++;
            }
            if (start + count >= chars_size) {
                flag = false;
            }
            result.push_back(chars[start]);
            // Change start before editing count
            start += count;
            if (count != 1) {
                int power = 10;
                while (count / power > 0) {
                    power *= 10;
                }
                while (power != 10) {
                    power /= 10;
                    int cur = count / power;
                    result.push_back('0' + cur);
                    count -= cur * power;
                }
                result.push_back('0' + count);
            }
            count = 0;
        }
        chars = result;
        return chars.size();
    }
};