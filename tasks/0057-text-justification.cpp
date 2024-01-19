#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result_vec;
        int i = 0, j = 0;
        int size = 0;
        while (i + j < words.size()) {
            string result = "";
            while (i + j < words.size() &&
                   size + words[i + j].size() + (j > 0) <= maxWidth) {
                size += words[i + j].size();
                size += (j > 0);
                j++;
            }
            // cout << "i = " << i << " , j = " << j << "\n";
            int spaces_left = maxWidth - size;
            // j == a number of the words in the current line
            int additional_spaces;
            int first_word_spaces;
            if (i + j >= words.size() || j == 1) {
                additional_spaces = 0;
                first_word_spaces = 0;
            } else {
                additional_spaces = spaces_left / (j - 1);
                first_word_spaces = spaces_left % (j - 1);
            }
            /*
            cout << "spaces_left = " << spaces_left << "\n";
            cout << "size = " << size << "\n";
            cout << "additional = " << additional_spaces << "\n";
            cout << "first_w = " << first_word_spaces << "\n";
            */
            for (int t = 0; t < j; t++) {
                result += words[i + t];
                if (first_word_spaces >= 0) {
                    first_word_spaces--;
                }
                if (t != j - 1) {
                    result += std::string(
                        additional_spaces + (first_word_spaces >= 0) + 1, ' ');
                }
            }

            if (i + j >= words.size() || j == 1) {
                result += std::string(maxWidth - result.size(), ' ');
                // cout << "here?\n";
            }
            i += j;
            j = 0;
            size = 0;
            result_vec.push_back(result);
        }
        return result_vec;
    }
};

// Quite a terrible code, naming and etc (5am coding moment)