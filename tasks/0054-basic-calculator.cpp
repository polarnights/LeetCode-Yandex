#include <deque>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int calculate(string s) {
        deque<string> current;
        // Parsing
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                current.push_back("(");
            } else if (s[i] == ' ') {
                continue;
            } else if (s[i] == ')') {
                int cur = 0;
                int result = 0;
                while (current.back() != "(") {
                    if (current.back() == "+") {
                        result += cur;
                        cur = 0;
                    } else if (current.back() == "-") {
                        result -= cur;
                        cur = 0;
                    } else {
                        cur = stoi(current.back());
                    };
                    current.pop_back();
                }
                result += cur;
                current.pop_back();
                if (!current.empty() && current.back() == "NEG") {
                    result *= -1;
                    current.pop_back();
                    current.push_back("+");
                }
                current.push_back(to_string(result));
            } else if (s[i] == '+') {
                current.push_back("+");
            } else if (s[i] == '-') {
                if (s[i + 1] == '(') {
                    current.push_back("NEG");
                } else {
                    current.push_back("-");
                }
            } else {
                int j = i;
                string temp = "";
                while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
                    temp += s[j];
                    j++;
                }
                current.push_back(temp);
                i = j - 1;
            }
        }

        // Debug

        /*
        for (auto& elem : current) {
            cout << elem << "\n";
        }
        */

        // Actually calculating

        int cur = 0;
        int result = 0;
        while (!current.empty()) {
            if (current.back() == "+") {
                result += cur;
                cur = 0;
            } else if (current.back() == "-") {
                result -= cur;
                cur = 0;
            } else {
                cur = stoi(current.back());
            };
            current.pop_back();
        }
        result += cur;

        return result;
    }
};

// Works very slow and takes to much memory (?)