#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class maxStack {
    private:
    vector<int> query;
    vector<pair<int, int>> maximums;

    public:
    void push(int x) {
        query.push_back(x);
        if (maximums.empty()) {
            maximums.emplace_back(x, 0);
            return;
        }
        auto current = maximums.back();
        if (x >= current.first) {
            maximums.emplace_back(x, maximums.size());
        } else {
            maximums.push_back(current);
        }
    }

    int pop() {
        if (query.empty()) {
            return -1;
        }
        int result = query.back();
        query.pop_back();
        maximums.pop_back();
        return result;
    }

    int top() {
        return query.back();
    }

    int peekMax() {
        return maximums.back().first;
    }

    int popMax() {
        int result = maximums.back().first, idx = maximums.back().second;
        cout << "DEBUG | max = " << result << " at idx = " << idx << "\n";
        query.erase(query.begin() + idx);
        maximums.erase(maximums.begin() + idx);
        for (size_t i = idx; i < maximums.size(); i++) {
            if (i != 0) {
                auto current = maximums[i - 1];
                if (maximums[i - 1].first > query[i]) {
                    maximums[i] = maximums[i - 1];
                } else {
                    maximums[i] = {query[i], i};
                }
            }
        }
        return result;
    }
};

int main() {
    auto stack = maxStack();
    stack.push(5); 
    stack.push(1);
    stack.push(5);
    cout << stack.top() << "\n"; // -> 5
    cout << stack.popMax() << "\n"; // -> 5
    cout << stack.top() << "\n"; // -> 1
    cout << stack.peekMax() << "\n"; // -> 5
    cout << stack.pop() << "\n"; // -> 1
    cout << stack.top() << "\n"; // -> 5
}