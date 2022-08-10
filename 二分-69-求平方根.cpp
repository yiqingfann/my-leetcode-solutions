// https://leetcode.com/problems/sqrtx/

class Solution {
  public:
    int mySqrt(int x) {
        int l = 0, r = x;

        while (l < r) {
            int mid = (l + 1ll + r) >> 1; // note: avoid overflow
            if (mid <= x / mid) l = mid;  // note: avoid overflow
            else r = mid - 1;
        }

        return r;
    }
};