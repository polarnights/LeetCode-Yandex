#include <iostream>
#include <queue>

using namespace std;

class HitCounter {
    private:
    queue<int> query;

    public:
    HitCounter() = default;

    void hit(int time) {
        query.push(time);
    }

    int getHits(int time) {
        while (!query.empty() && time - query.front() >= 300) {
            query.pop();
        }
        return query.size();
    }

    ~HitCounter() = default;
};

int main() {
    //  Testing my solution (copied from leetcode)
    // hit at timestamp 1.
    HitCounter* counter = new HitCounter();
    counter->hit(1);

    // hit at timestamp 2.
    counter->hit(2);

    // hit at timestamp 3.
    counter->hit(3);

    // get hits at timestamp 4, should return 3.
    cout << counter->getHits(4) << "\n";

    // hit at timestamp 300.
    counter->hit(300);

    // get hits at timestamp 300, should return 4.
    cout << counter->getHits(300) << "\n";

    // get hits at timestamp 301, should return 3.
    cout << counter->getHits(301) << "\n";
}
// TODO: Find out when it is needed to specify c-tor and d-tor manually
// TODO: Find out about universal solution from here
// https://leetcode.com/discuss/interview-question/178662/Design-a-Hit-Counter/