#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result = {};
        int first = 0;
        int second = 0;
        // Two intervals intersect if:
        //...s1[......]e1.......
        //......s2[.......]e2...
        // s2 <= e1 and s1 <= e2
        // OR
        //......s1[.......]e1...
        //...s2[......]e2.......
        // s1 <= e2 and s2 <= e1
        // Same condition
        while (first < firstList.size() && second < secondList.size()) {
            if (secondList[second][0] <= firstList[first][1] && \
            firstList[first][0] <= secondList[second][1]) {
                result.push_back({max(firstList[first][0], secondList[second][0]), min(firstList[first][1], secondList[second][1])});
            }
            if (firstList[first][1] >= secondList[second][1]) {
                second++;
            } else {
                first++;
            }
        }
        return result;
        // Could it be solved easier with the same formula and checking that
        // max(...) <= min(...)?
    }
};