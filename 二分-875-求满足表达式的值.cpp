// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
  public:
    int get(vector<int> &piles, int mid) {
        int res = 0;

        for (auto x : piles) {
            res += (x + mid - 1) / mid; // note: a/b ceil <=> (a+b-1)/b floor
        }

        return res;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1, r = 1e9;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (get(piles, mid) <= h) r = mid;
            else l = mid + 1;
        }

        return r;
    }
};