class Solution {
  public:
    /*
    My initial idea
    Binsearch seems to be faster which is completely understandable
    But I'm not gonna write that code =)
    */
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int64_t fast = 1;
        while (fast * fast * 4 <= x) {
            fast *= 2;
        }
        while ((fast + 1) * (fast + 1) <= x) {
            fast++;
        }
        return fast;
    }
};