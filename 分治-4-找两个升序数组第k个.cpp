// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        double ans = 0;

        if ((l1 + l2) % 2 == 0) {
            int v1 = find_kth_smallest(nums1, 0, nums2, 0, (l1 + l2) / 2);
            int v2 = find_kth_smallest(nums1, 0, nums2, 0, (l1 + l2) / 2 + 1);
            ans = (v1 + v2) / 2.0;
        } else {
            ans = find_kth_smallest(nums1, 0, nums2, 0, (l1 + l2) / 2 + 1);
        }

        return ans;
    }

    int find_kth_smallest(vector<int> &nums1, int s1, vector<int> &nums2,
                          int s2, int k) {
        // make nums1 the shorter
        if (nums1.size() - s1 > nums2.size() - s2)
            return find_kth_smallest(nums2, s2, nums1, s1, k);

        // check nums1 exists
        if (s1 == nums1.size()) return nums2[s2 + k - 1];

        // base condition
        if (k == 1) return min(nums1[s1], nums2[s2]);

        int len = min(k / 2, int(nums1.size()) - s1);
        int p1 = s1 + len - 1, p2 = s2 + len - 1;
        if (nums1[p1] < nums2[p2]) {
            return find_kth_smallest(nums1, p1 + 1, nums2, s2, k - len);
        } else {
            return find_kth_smallest(nums1, s1, nums2, p2 + 1, k - len);
        }
    }
};