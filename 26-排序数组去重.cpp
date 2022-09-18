class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // invariant: i is the pos of last elem in final result
        int n = nums.size();
        int i = -1;
        // enumerate each element
        for (int j = 0; j < n; ++j) {
            // if there's dup, find the last one
            while (j + 1 < n && nums[j] == nums[j + 1]) ++j;
            // swap it to the correct place
            swap(nums[++i], nums[j]);
        }
        return i + 1;
    }
};