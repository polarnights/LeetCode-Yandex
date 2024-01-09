#include <iostream>
#include <unordered_map>

using namespace std;

const int TIME_SECS = 300;

class HitCounter {
  private:
    unordered_map<int, int> count_hits;
    unordered_map<int, int> time_of_last_hit;

  public:
    void hit(int time) {
        int idx = time % TIME_SECS;
        if (time_of_last_hit[idx] == time) {
            count_hits[idx]++;
        } else {
            time_of_last_hit[idx] = time;
            count_hits[idx] = 1;
        }
    }

    int getHits(int time) {
        int result = 0;
        for (auto &elem : count_hits) {
            if (time - time_of_last_hit[elem.first] < TIME_SECS) {
                result += elem.second;
            }
        }
        return result;
    }
};

int
main() {
    //  Testing my solution (copied from leetcode)
    // hit at timestamp 1.
    HitCounter counter;
    counter.hit(1);

    // hit at timestamp 2.
    counter.hit(2);

    // hit at timestamp 3.
    counter.hit(3);

    // get hits at timestamp 4, should return 3.
    cout << counter.getHits(4) << "\n";

    // hit at timestamp 300.
    counter.hit(300);

    // get hits at timestamp 300, should return 4.
    cout << counter.getHits(300) << "\n";

    // get hits at timestamp 301, should return 3.
    cout << counter.getHits(301) << "\n";
}