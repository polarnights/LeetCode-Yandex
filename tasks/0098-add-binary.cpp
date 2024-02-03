class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        string result(max(a.size(), b.size()), '0');
        int i = a.size() - 1;
        int j = b.size() - 1;
        bool flag = false;
        while (i >= 0 && j >= 0) {
            int overall = (a[i] == '1') + (b[j] == '1') + flag;
            if (overall >= 2) {
                flag = true;
            } else {
                flag = false;
            }
            if (overall % 2 == 1) {
                result[i] = '1';
            }
            i--;
            j--;
        }
        while (i >= 0) {
            int overall = (a[i] == '1') + flag;
            if (overall == 2) {
                flag = true;
            } else {
                flag = false;
            }
            if (overall % 2 == 1) {
                result[i] = '1';
            }
            // result = ('0' + (overall % 2)) + result;
            i--;
        }
        while (j >= 0) {
            int overall = (b[j] == '1') + flag;
            if (overall == 2) {
                flag = true;
            } else {
                flag = false;
            }
            if (overall % 2 == 1) {
                result[j] = '1';
            }
            // result = ('0' + (overall % 2)) + result;
            j--;
        }
        // cout << flag;
        // cout << result << "\n";
        if (flag) {
            result = "1" + result;
        }
        return result;
    }
};