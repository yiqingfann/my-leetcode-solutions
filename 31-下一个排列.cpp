class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        // idea: the new array must have a position i that new[i] > old[i]
        // we want to keep the position i as close to the end as possible
        // e.g. for 1,2,4,5,3
        // can we keep 1,2,4?
        //     want a minumum value > 5 to replace 5, the left is 3
        //     cannot do that
        // can we keep 1,2?
        //     need a minumum value > 4 to replace 4, the left is 5, 3
        //     replace 4 with 5, sort the remaining
        //     get 1,2,5,3,4

        // // solution 1
        // int n = nums.size();
        // for (int i = n - 2; i >= 0; --i) {
        //     // find the min value > nums[i] in nums[i + 1 : end]
        //     int minv = 0x3f3f3f3f, minp = -1;
        //     for (int j = i + 1; j < n; ++j) {
        //         if (nums[j] > nums[i] && nums[j] < minv) {
        //             minv = nums[j], minp = j;
        //         }
        //     }
        //     // if not found, check next position
        //     if (minp == -1) continue;
        //     // if found, swap and sort the remaining
        //     swap(nums[i], nums[minp]);
        //     sort(nums.begin() + i + 1, nums.end());
        //     return;
        // }
        // // if not possible, return the smallest permutation
        // sort(nums.begin(), nums.end());

        // solution 2
        int n = nums.size();
        // find the rightmost position that can be increased
        int p = n - 2;
        while (p >= 0 && nums[p] >= nums[p + 1]) --p;
        // if already the largest permutation, reverse and return
        if (p == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // find the position of min val > nums[p]
        int q = p + 1;
        while (q < n && nums[q] > nums[p]) ++q;
        swap(nums[p], nums[q - 1]);
        reverse(nums.begin() + p + 1, nums.end());
    }
};