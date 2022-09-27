// https://leetcode.com/problems/binary-search/

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        // init l and r to be search range
        // find the last element that is <= target
        // if the found position val == target, return pos
        // else return -1

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }

        return (nums[r] == target) ? r : -1;
    }
};