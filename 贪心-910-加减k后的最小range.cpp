// https://leetcode.com/problems/smallest-range-ii/

class Solution {
  public:
    int smallestRangeII(vector<int> &nums, int k) {
        // idea: first sort nums, must exist an optimal soln +++... then ---...
        // because the final range is the union of all ranges
        // if exist two elem -+, then switch to +- reduces then range of these
        // two elems so we only need to enumerate all possible boundaries

        sort(nums.begin(), nums.end());
        int n = nums.size();

        // special case: all + / -
        int ans = nums[n - 1] - nums[0];

        // enumerate all possible i, where [0, i] + k, [i + 1, n - 1] - k
        for (int i = 0; i + 1 < n; i++) {
            int ma = max(nums[i] + k, nums[n - 1] - k);
            int mi = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, ma - mi);
        }

        return ans;
    }
};