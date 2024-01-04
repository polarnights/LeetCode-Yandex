#include <iostream>
#include <vector>
#include <unordered_set>

/*
Find if there is a y-axis-parallel line that symmetrically splits all dots.
*/

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int>& pair) const {
        return pair.first ^ pair.second;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::unordered_set<std::pair<int, int>, pair_hash> dots;
    int a, b;
    int x_min = INT_MAX, x_max = INT_MIN;
    for (int i = 0; i != n; i++) {
        std::cin >> a >> b;
        dots.insert(std::make_pair(a, b));
        if (a < x_min) x_min = a;
        if (a > x_max) x_max = a;
    }
    
    int64_t x_mid_doubled = (x_min + x_max);

    for (auto& elem : dots) {
        if (dots.count(std::make_pair(x_mid_doubled - elem.first, elem.second)) == 0) {
            std::cout << "false\n";
            return 0;
        }
    }
    std::cout << "true\n";
}