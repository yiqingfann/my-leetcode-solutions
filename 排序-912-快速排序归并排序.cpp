// https://leetcode.com/problems/sort-an-array/
// https://www.youtube.com/watch?v=hVl2b3bLzBw

// soln 1: quick sort

class Solution {
  public:
    void qksort(vector<int> &nums, int l, int r) {
        // base case
        if (l >= r) return;
        // partition
        int i = l, j = r, x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[i] < x) ++i;
            while (nums[j] > x) --j;
            if (i < j) {
                swap(nums[i], nums[j]);
                ++i, --j;
                if (i == j && nums[j] > x) --j;
            }
        }
        // deal with left and right part
        qksort(nums, l, j);
        qksort(nums, j + 1, r);
    }

    vector<int> sortArray(vector<int> &nums) {
        qksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// soln 2: merge sort O(n) space

class Solution {
  public:
    const int N = 5e4 + 10;
    vector<int> tmp;
    Solution() : tmp(N, 0) {}

    void mgsort(vector<int> &nums, int l, int r) {
        if (l >= r) return;

        // get result of subproblem
        int mid = (l + r) >> 1;
        mgsort(nums, l, mid);
        mgsort(nums, mid + 1, r);

        // construct result from sub results
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) tmp[k] = nums[i], ++i, ++k;
            else tmp[k] = nums[j], ++j, ++k;
        }

        while (i <= mid) tmp[k] = nums[i], ++i, ++k;
        while (j <= r) tmp[k] = nums[j], ++j, ++k;

        for (int i = l, j = 0; i <= r; ++i, ++j) nums[i] = tmp[j];
    }

    vector<int> sortArray(vector<int> &nums) {
        mgsort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// soln 3: merge sort with O(1) space

class Solution {
  public:
    void mgsort(vector<int> &nums, int l, int r) {
        if (l >= r) return;

        // get result of subproblem
        int mid = (l + r) >> 1;
        mgsort(nums, l, mid);
        mgsort(nums, mid + 1, r);

        // construct result from sub results
        for (int gap = (r - l + 1 + 1) / 2; gap >= 1;
             gap = (gap != 1) ? (gap + 1) / 2 : gap / 2) {
            for (int i = l, j = l + gap; j <= r; ++i, ++j) {
                if (nums[i] > nums[j]) swap(nums[i], nums[j]);
            }
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        mgsort(nums, 0, nums.size() - 1);
        return nums;
    }
};