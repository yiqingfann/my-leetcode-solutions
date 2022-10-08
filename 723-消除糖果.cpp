// https://leetcode.com/problems/candy-crush/submissions/

class Solution {
  public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        // for each cell, check its 4 dirs, mark if can be crushed
        // for each col, scan and store it should be in a new arr, then copy
        // back repeat until nothing changes
        int n = board.size(), m = board[0].size();

        while (true) {
            bool markExist = false;
            vector<vector<bool>> mark(n, vector<bool>(m, false));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == 0) continue;
                    if (j + 2 < m && board[i][j] == board[i][j + 1] &&
                        board[i][j] == board[i][j + 2]) {
                        mark[i][j] = true, markExist = true, ++j;
                        while (j < m && board[i][j] == board[i][j - 1])
                            mark[i][j] = true, ++j;
                        --j;
                    }
                }
            }
            for (int j = 0; j < m; ++j) {
                for (int i = 0; i < n; ++i) {
                    if (board[i][j] == 0) continue;
                    if (i + 2 < n && board[i][j] == board[i + 1][j] &&
                        board[i][j] == board[i + 2][j]) {
                        mark[i][j] = true, markExist = true, ++i;
                        while (i < n && board[i][j] == board[i - 1][j])
                            mark[i][j] = true, ++i;
                        --i;
                    }
                }
            }
            if (!markExist) break;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!mark[i][j]) continue;
                    board[i][j] = 0;
                }
            }
            for (int j = 0; j < m; ++j) {
                for (int i = n - 1, k = n - 1; i >= 0; --i) {
                    if (board[i][j] != 0) continue;
                    while (k >= 0 && (k >= i || board[k][j] == 0)) --k;
                    if (k >= 0) swap(board[i][j], board[k][j]);
                }
            }
        }
        return board;
    }
};