#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> &Solve(vector<int> &numbers, int l, int r, int weight) {
        int left_numbers = 0;
        int right_numbers = 0;
        for (int i = 0; i < l; i++) {
            numbers[i] -= (l - i);
        }
        for (int i = r + 1; i < numbers.size(); i++) {
            numbers[i] -= (i - r);
        }
        sort(numbers.begin(), numbers.begin() + l);
        sort(numbers.begin() + r + 1, numbers.end(), greater<int>());
        // ?

        return numbers;
    }
};

int
main() {}