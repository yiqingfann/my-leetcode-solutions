// https://leetcode.com/problems/word-search/

class Solution {
  public:
    vector<vector<bool>> used;
    bool dfs(vector<vector<char>> &board, int i, int j, string word, int pos) {
        // return if a match of word[pos:] can be found starting at board[i][j]

        // base case
        if (board[i][j] != word[pos]) return false;
        if (pos == word.size() - 1) return true;

        // try all possibility
        used[i][j] = true;
        const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
        for (int dir = 0; dir < 4; ++dir) {
            int nexi = i + di[dir], nexj = j + dj[dir];
            if (nexi >= board.size() || nexi < 0 || nexj >= board[0].size() ||
                nexj < 0)
                continue;                   // a valid cell
            if (used[nexi][nexj]) continue; // an unused cell
            if (dfs(board, nexi, nexj, word, pos + 1)) return true;
        }
        used[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        used = vector<vector<bool>>(board.size(),
                                    vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != word[0]) continue;
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};