// https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
  public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        unordered_map<int, int> h1, h2;
        int ans = 0;

        for (int r = 0, l1 = 0, l2 = 0; r < nums.size(); r++) {
            // add current val to map
            h1[nums[r]]++, h2[nums[r]]++;
            // move l1 to position where first time [l1, r] has k diff num
            while (h1.size() > k) {
                int t = nums[l1];
                l1++;
                h1[t]--;
                if (h1[t] == 0) h1.erase(t);
            }
            // move l2 to position where first time [l2, r] has k - 1 diff num
            while (h2.size() > k - 1) {
                int t = nums[l2];
                l2++;
                h2[t]--;
                if (h2[t] == 0) h2.erase(t);
            }
            // now any elem in [l1, l2 - 1] is a valid left endpoint
            ans += l2 - l1;
        }

        return ans;
    }
};