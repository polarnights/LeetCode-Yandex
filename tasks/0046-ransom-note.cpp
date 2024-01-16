#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counter;
        for (int i = 0; i < ransomNote.size(); i++) {
            counter[ransomNote[i]]--;
        }
        for (int i = 0; i < magazine.size(); i++) {
            counter[magazine[i]]++;
        }
        for (auto &elem : counter) {
            if (elem.second < 0) {
                return false;
            }
        }
        return true;
    }
};