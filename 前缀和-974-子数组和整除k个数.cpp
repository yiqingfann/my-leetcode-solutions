// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
  public:
    int subarraysDivByK(vector<int> &nums, int k) {
        // idea: subarray -> enumerate all right endpoints
        // idea: sum range sum -> prefix sum
        // idea: si - sj-1 divide by k -> si % k and sj-1 % k independent

        // compute prefix sum
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        // enumerate right endpoint
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int ans = 0;
        for (int r = 1; r < n + 1; ++r) {
            int t = (s[r] % k + k) % k; // note: negative number mod
            ans += cnt[t];
            cnt[t]++;
        }

        return ans;
    }
};