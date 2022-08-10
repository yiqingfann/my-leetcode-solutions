// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int nrow = matrix.size(), ncol = matrix[0].size();
        int l = 0, r = nrow * ncol - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / ncol][mid % ncol] >= target) r = mid;
            else l = mid + 1;
        }

        return matrix[r / ncol][r % ncol] == target;
    }
};