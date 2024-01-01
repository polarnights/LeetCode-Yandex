/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to the closest person.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int special_count = 0;
    int current_count = 0;
    int max_count = 1;
    bool flag_start_seat = true;
    for (int i = 0; i != n; i++) {
        int a;
        std::cin >> a;
        if (a == 1) {
            if (flag_start_seat) {
                flag_start_seat = false;
                special_count = current_count;
            } else if (current_count > max_count) {
                max_count = current_count;
            }
            current_count = 0;
        } else {
            current_count += 1;
        }
    }
    if (current_count > special_count) {
        special_count = current_count;
    }
    // (!) Целочисленное деление с округлением вверх: x / y -> ceil = [(x - 1) / y] + 1.
    std::cout << std::max((max_count - 1) / 2 + 1, special_count) << "\n";
}