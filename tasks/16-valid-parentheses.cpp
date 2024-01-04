#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        stack<char> order;

        map<char, char> opposite_symbol = {{'(', ')'}, {'[', ']'}, {'{', '}'},
                                           {')', '('}, {']', '['}, {'}', '{'}};

        for (auto elem : s) {
            if (elem == '(' || elem == '[' || elem == '{') {
                order.push(elem);
            } else {
                if (order.empty()) {
                    return false;
                }
                if (order.top() == opposite_symbol[elem]) {
                    order.pop();
                } else {
                    return false;
                }
            }
        }
        if (!order.empty()) {
            return false;
        }
        return true;
    }
};