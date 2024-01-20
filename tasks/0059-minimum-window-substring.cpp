#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        int result = INT_MAX;
        string result_str = "";
        unordered_map<char, int> count;
        for (char elem : t) {
            count[elem]--;
        }
        int count_wrong_pos = 0;
        int count_wrong_neg = 0;
        for (auto &elem : count) {
            count_wrong_neg++;
        }
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            // cout << "1\n";
            /*
            cout << "Right = " << right << ", left = " << left << " | WN = " <<
            count_wrong_neg << " | WP = " << count_wrong_pos << "\n"; cout <<
            "Current string : " << s.substr(left, right - left) << "\n";
            */
            if (right - left < t.size() || count_wrong_neg > 0) {
                count[s[right]]++;
                if (count[s[right]] == 0) {
                    count_wrong_neg--;
                } else if (count[s[right]] == 1) {
                    count_wrong_pos++;
                }
                right++;
            } else if (count_wrong_neg == 0) {
                while (count_wrong_pos > 0 && count[s[left]] > 0) {
                    /*
                    cout << "(!) Right = " << right << ", left = " << left << "
            | WN = " << count_wrong_neg << " | WP = " << count_wrong_pos <<
            "\n"; cout << "(!) Current string : " << s.substr(left, right -
            left) << "\n";
                    */
                    count[s[left]]--;
                    if (count[s[left]] == 0) {
                        count_wrong_pos--;
                    }
                    left++;
                    // cout << "6\n";
                }
                /*
                cout << "(!) Right = " << right << ", left = " << left << " | WN
            = " << count_wrong_neg << " | WP = " << count_wrong_pos << "\n";
            cout << "(!) Current string : " << s.substr(left, right - left) <<
            "\n";
                */
                if (right - left < result) {
                    result = right - left;
                    result_str = s.substr(left, right - left);
                    // cout << "Result changed to " << result << " | result_line
                    // = '" << result_str << "'\n";
                }
                count[s[left]]--;
                if (count[s[left]] == -1) {
                    count_wrong_neg++;
                } else if (count[s[left]] == 0) {
                    count_wrong_pos--;
                }
                // count_wrong_neg++;
                left++;
                // cout << "4\n";
                // }
                // cout << "5\n";
            }
        }
        /*
        cout << "Right = " << right << ", left = " << left << " | WN = " <<
        count_wrong_neg << " | WP = " << count_wrong_pos << "\n"; cout <<
        "Current string : " << s.substr(left, right - left) << "\n";
        */
        if (count_wrong_neg != 0) {
            // cout << "wrong last\n";
            // string result_str_final(result_str);
            return result_str;
        }
        /*
        cout << "good last\n";
        cout << "LOOK HERE | " << count_wrong_pos << " " << count[left] << ";
        elem = " << s[left] <<  "\n";
        */
        while (count_wrong_pos > 0 && count[s[left]] > 0) {
            count[s[left]]--;
            if (count[s[left]] == 0) {
                count_wrong_pos--;
            }
            left++;
            // cout << "6\n";
        }
        /*
        cout << "Right = " << right << ", left = " << left << " | WN = " <<
        count_wrong_neg << " | WP = " << count_wrong_pos << "\n"; cout <<
        "Current string : " << s.substr(left, right - left) << "\n";
        */
        if (right - left < result) {
            // cout << "correct last\n";
            // result = right - left;
            result_str = s.substr(left, right - left);
        }
        // string result_str_final(result_str);
        return result_str;
    }
};

// Note that substring taking can be changed to storing right, left
// and creating a substring only at the very end