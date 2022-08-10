// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int l = INT_MIN, r = INT_MAX;

        // binary search for first element v with property: nelem in matrix <= v
        // is >=k
        while (l < r) {
            int t = ((long long)l + r) >> 1;
            // count nelem <= t in matrix
            int cnt = 0, j = n - 1;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > t) j--;
                cnt += j + 1;
            }
            if (cnt >= k) r = t;
            else l = t + 1;
        }

        return r;
    }
};