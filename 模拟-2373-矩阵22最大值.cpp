// https://leetcode.com/problems/largest-local-values-in-a-matrix/

class Solution {
  public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - 2);

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int val = -1;
                for (int p = i; p < i + 3; p++) {
                    for (int q = j; q < j + 3; q++) {
                        val = max(val, grid[p][q]);
                    }
                }
                ans[i].push_back(val);
            }
        }

        return ans;
    }
};