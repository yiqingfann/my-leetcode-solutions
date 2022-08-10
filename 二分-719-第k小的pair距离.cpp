// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

class Solution {
  public:
    int countLeqPairs(vector<int> &nums, int t) {
        int j = 0, cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] - nums[j] > t) j++;
            cnt += i - j;
        }

        return cnt;
    }

    int smallestDistancePair(vector<int> &nums, int k) {
        int l = 0, r = 1e6;
        sort(nums.begin(), nums.end());

        while (l < r) {
            int t = (l + r) >> 1;
            if (countLeqPairs(nums, t) >= k) r = t;
            else l = t + 1;
        }

        return r;
    }
};