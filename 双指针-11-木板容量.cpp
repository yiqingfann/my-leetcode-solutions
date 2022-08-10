// https://leetcode.com/problems/container-with-most-water/

class Solution {
  public:
    int maxArea(vector<int> &height) {
        // i, j start from two ends
        // if there is a better solution, it must not contain the shorter one
        int ans = 0;

        for (int i = 0, j = height.size() - 1; i < j;) {
            int cur = (j - i) * min(height[i], height[j]);
            ans = max(ans, cur);
            if (height[i] < height[j]) i++;
            else j--;
        }

        return ans;
    }
};