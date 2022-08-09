// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        // search for end index of first half
        // important: must find last elem >= nums[0], not first elem < nums[0]
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        // search for target in correct half
        if (target >= nums[0]) l = 0;
        else l++, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        // important: must use r not l, when nums has length 1
        return nums[r] == target ? l : -1;
    }
};