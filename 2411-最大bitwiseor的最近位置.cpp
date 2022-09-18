class Solution {
  public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> pos(32, -1);
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            int t = i;
            for (int j = 0; j < 32; ++j) {
                if ((nums[i] >> j) & 1) {
                    pos[j] = i;
                } else if (pos[j] != -1) {
                    t = max(t, pos[j]);
                }
            }
            ans[i] = t - i + 1;
        }
        return ans;
    }
};