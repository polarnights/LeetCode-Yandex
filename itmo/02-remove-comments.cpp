#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string removeComments(string input) {
        int size = static_cast<int>(input.size());   // just for -WError
        if (size == 0) {
            return "";
        }
        int ignoreCurrentFlag = 0;
        // 0 - there is no ongoing comment
        // 1 - there is one-line ongoing comment "// ..."
        // 2 - there is single-line ongoing comment " /* ... */"
        // 3 - there is multi-line ongoing comment "/*...\n...*/";
        string output = "";
        for (int i = 0; i < size; i++) {
            if (ignoreCurrentFlag == 0) {
                if (input[i] == '/' && i < size - 1) {
                    if (input[i + 1] == '/') {
                        ignoreCurrentFlag = 1;
                        i++;
                        continue;
                    } else if (input[i + 1] == '*') {
                        ignoreCurrentFlag = 2;
                        i++;
                        continue;
                    }
                }
                output += input[i];
            } else if (ignoreCurrentFlag == 1) {
                if (input[i] == '\n') {
                    ignoreCurrentFlag = 0;
                    output += input[i];
                }
            } else {
                if (input[i] == '\n') {
                    ignoreCurrentFlag = 3;
                }
                if (input[i] == '*' && i < size - 1) {
                    if (input[i + 1] == '/') {
                        if (ignoreCurrentFlag == 3) {
                            output += '\n';
                        }
                        ignoreCurrentFlag = 0;
                        i++;
                    }
                }
            }
        }
        return output;
    }
};

int
main() {
    Solution solution;
    string input = "/*"
                   "* My first ever program in Java!"
                   "*/"
                   "class Hello { // class body starts here\n"
                   "\n"
                   " /* main method */\n"
                   "  public static void main(String[] args/* we put command"
                   "line arguments here*/) {\n"
                   "    // this line prints my first greeting to the screen\n"
                   "    System.out.println(\" Hi !\"); // :)\n"
                   "  }\n"
                   "} // the end\n"
                   "// to be continued...";
    cout << solution.removeComments(input);
}