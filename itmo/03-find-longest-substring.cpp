#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string findLongestPrefix(vector<string> &strings) {
        if (strings.size() == 0) {
            return "";
        }
        int i = 0;
        int minSize = INT_MAX;
        for (int i = 0; i < strings.size(); i++) {
            if (strings[i].size() < minSize) {
                minSize = strings[i].size();
            }
        }

        for (int i = 0; i < minSize; i++) {
            for (int j = 0; j < strings.size(); j++) {
                if (strings[j][i] != strings[0][i]) {
                    if (i == 0) {
                        return "";
                    }
                    return strings[0].substr(0, i);
                }
            }
        }
        return strings[0];
    }
};

int
main() {
    Solution solution;
    vector<string> inputStrings = {};
    /*
    My other testcases
    {"flower","flow","flight"};
    {"1234lasfakfas", "1234kgfsamdfksd", "3331234", "1234oafoslasf",
    "2345asklaksfas", "1234asfkaf"};
    {"ciao", "ciao", "ciao", "ciao"};
    {""};
    {"1"};
    {};
    */
    cout << solution.findLongestPrefix(inputStrings) << "\n";
}