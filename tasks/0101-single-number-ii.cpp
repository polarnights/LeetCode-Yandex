class Solution {
  public:
    int64_t singleNumber(vector<int> &nums) {
        // Applying xor to every elem we get xor of all elements from set(nums)
        /*
        int64_t cur = 0;
        int64_t sum = 0;
        for (auto& elem : nums) {
            cur ^= elem;
            sum += elem;
        }
        cout << cur << " " << sum << "\n";
        return (3 * cur - sum) / 2;
        */
        vector<int> count_bits(32, 0);   // 32 = bits in int
        for (auto &elem : nums) {
            for (int i = 0; i < 32; i++) {
                count_bits[i] += ((elem >> i) & 1);
            }
        }
        int result = 0;
        for (int i = 0; i < 32; i++) {
            cout << count_bits[i];
            if (count_bits[i] % 3 != 0) {
                result += (1 << i);
            }
        }
        return result;
    }
};