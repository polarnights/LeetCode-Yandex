#include <iostream>
#include <string>

using namespace std;

// isAlpha, isNum, ... -type functions info is found here
// https://en.cppreference.com/w/cpp/string/byte/isalpha

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        // Assuming O(1) memory is allowed
        size_t front = 0;
        size_t back = s.size() - 1;
        while (front < back) {
            while (!isalnum(s[front])) {
                front++;
                if (front >= s.size()) {
                    return true;
                }
            }
            while (!isalnum(s[back])) {
                back--;
                if (back < 0) {
                    return true;
                }
            }
            if (front >= back) {
                return true;
            }
            if (tolower(s[front]) != tolower(s[back])) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};