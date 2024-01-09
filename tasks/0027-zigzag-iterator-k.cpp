// TODO!
#include <deque>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

using namespace std;

class ZigZagIterator {
    int k;
    deque<pair<vector<int>::iterator, vector<int>::iterator>>
        order;   // it.begin(), it.end()

  public:
    template <typename T, typename... Args>
    ZigZagIterator(T &t, Args &...args) {
        init(t, args...);
    }

    template <typename T> void init(T &t) {
        if constexpr (is_same_v<T, int>) {
            cout << "solo-init | t is int\n";
            k = t;
        } else {
            cout << "solo-init | t is NOT int\n";
            order.push_back(make_pair(t.begin(), t.end()));
        }
    }

    template <typename T, typename... Args> void init(T &t, Args &...args) {
        if constexpr (is_same_v<T, int>) {
            cout << "multi-init | t is int\n";
            k = t;
        } else {
            cout << "multi-init | t is NOT int\n";
            order.push_back(make_pair(t.begin(), t.end()));
        }
        init(args...);
    }

    int next_elem() {
        cout << "DEBUG | order.size() == " << order.size() << "\n";
        while (!order.empty() && order.front().first == order.front().second) {
            order.pop_front();
            cout << "DEBUG | empty element deleted!\n";
        }
        if (order.empty()) {
            cout << "Queue ended!\n";
            return -1;
        }
        auto current = order.front();
        order.pop_front();
        cout << "TEST  | " << *current.first << "\n";
        /*
        Next or it++ tyrade
            Although the expression ++c.begin() often compiles, it is not
            guaranteed to do so: c.begin() is an rvalue expression, and
            there is no LegacyInputIterator requirement that specifies that
            increment of an rvalue is guaranteed to work. In particular,
            when iterators are implemented as pointers or its operator++ is
            lvalue-ref-qualified,
            ++c.begin() does not compile, while std::next(c.begin()) does.
            TODO: next == advance (?)
        */
        if (next(current.first) != current.second) {
            order.push_back(make_pair(next(current.first), current.second));
        }
        return *current.first;
    }
};

int
main() {
    vector<int> first = {1, 4, 7};
    vector<int> second = {2, 5, 8};
    vector<int> third = {3, 6, 9};
    int k = 3;
    ZigZagIterator zigzag(k, first, second, third);
    while (zigzag.next_elem() != -1) {
        // ...
    }
}