#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int hIndex(vector<int> &citations) {
        int size = citations.size();
        vector<int> count(1001, 0);
        for (auto &elem : citations) {
            count[elem]++;
        }
        int current = 0;
        int current_idx = 0;
        while (size - current >= current_idx) {
            current += count[current_idx];
            current_idx++;
        }
        return current_idx - 1;
    }
};