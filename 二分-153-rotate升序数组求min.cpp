// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > nums[0]) l = mid;
            else r = mid - 1;
        }
        return nums[(r + 1) % nums.size()];
    }
};