// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0, j = n - 1, k = n - 1; i <= j;) {
            int vi = nums[i] * nums[i], vj = nums[j] * nums[j];
            if (vi > vj) {
                ans[k] = vi;
                i++, k--;
            } else {
                ans[k] = vj;
                j--, k--;
            }
        }

        return ans;
    }
};