// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
  public:
    vector<bool> used;

    bool dfs(int cg, int tg, int csum, int tsum, int start, vector<int> &nums) {
        // cg: current #formed group, tg: #target group
        // csum: current sum, tsum: target sum
        // start: position to start searching

        // base case
        if (cg == tg) return true;

        // try all choices
        for (int i = start; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (csum + nums[i] <= tsum) {
                used[i] = true;
                if (csum + nums[i] < tsum &&
                    dfs(cg, tg, csum + nums[i], tsum, i + 1, nums))
                    return true;
                if (csum + nums[i] == tsum && dfs(cg + 1, tg, 0, tsum, 0, nums))
                    return true;
                used[i] = false;
            }
            // optimize 2: failed at i, if it's the first or last element, all
            // fail
            if (csum == 0 || csum + nums[i] == tsum) return false;
            // optimize 3: failed at i, skip all val == nums[i]
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k) {
        used = vector<bool>(nums.size(), false);

        // compute target sum of each group
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int tsum = sum / k;

        // optimize 1: sort desc
        sort(nums.begin(), nums.end(), greater<int>());

        return dfs(0, k, 0, tsum, 0, nums);
    }
};