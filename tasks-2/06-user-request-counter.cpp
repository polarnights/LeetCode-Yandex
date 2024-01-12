#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int TIME_SECS = 600;   // 600 secs = 10 mins

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

class UserRequestCounter {
  private:
    unordered_map<string, HitCounter> count_hits;

    // TODO: Find out the difference between string and string_view
  public:
    void request(string user_id, int time) { count_hits[user_id].hit(time); }

    int countUsers(int time) {
        for (auto &elem : count_hits) {
            // todo
        }
    }
};

int
main() {
    UserRequestCounter req_count;
    req_count.request("vasya", 1);
    req_count.request("vasya", 2);
    req_count.request("vasya", 3);
    req_count.request("vasya", 4);
    req_count.request("petya", 10);
    req_count.request("petya", 10);
    req_count.request("petya", 11);
    cout << req_count.countUsers(12) << "\n";
    cout << req_count.countUsers(600) << "\n";
    cout << req_count.countUsers(601) << "\n";
    cout << req_count.countUsers(10000) << "\n";
}