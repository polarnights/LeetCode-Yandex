#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int countWords(string path) {
        ofstream myfile;
        try {
            myfile.open(path);
        } catch (...) {
            cout << "File could not be opened!\n";
            return 1;
        }
        // myfile ->input
        if (input.size() == 0) {
            return 0;
        }
        int counter = 0;
        bool isWordRN = false;
        for (int i = 0; i < input.size(); i++) {
            if (isWordRN) {
                if (input[i] == ' ' || input[i] == '\n') {
                    counter++;
                    isWordRN = false;
                }
            } else {
                if (input[i] != ' ' && input[i] != '\n') {
                    isWordRN = true;
                }
            }
        }
        if (isWordRN) {
            counter++;
        }
        return counter;
    }
};