#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        for (size_t i = 0; i < min(word1.size(), word2.size()); i++) {
            result += word1[i];
            result += word2[i];
        }
        for (int i = min(word1.size(), word2.size()); i < word1.size(); i++) {
            result += word1[i];
        }
        for (int i = min(word1.size(), word2.size()); i < word2.size(); i++) {
            result += word2[i];
        }
        return result;
    }
};