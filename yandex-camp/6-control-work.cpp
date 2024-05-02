#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int
main() {
    int a, b;
    cin >> a >> b;
    vector<vector<string>> result(b);
    for (auto &elem : result) {
        elem.resize(a + 1, "Y");
    }
    vector<int> given(a);
    for (int j = 0; j < a; j++) {
        cin >> given[j];
    }

    int counter = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a + 1; j++) {
            string word;
            cin >> word;
            if (j == 0) {
                result[i][j] = word;
            } else {
                if (word != "-") {
                    int res = stoi(word);
                    if (res < 0 || res > given[j - 1]) {
                        result[i][j] = "N";
                        counter++;
                    }
                }
            }
        }
    }

    cout << counter << "\n";
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a + 1; j++) {
            cout << result[i][j];
            if (j != a) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}