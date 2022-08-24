// https://leetcode.com/problems/sudoku-solver/

// soln 2: minor improve

class Solution {
  public:
    vector<vector<bool>> rused, cused, bused;

    bool dfs(vector<vector<char>> &board, int i, int j) {
        if (j == 9) i++, j = 0;

        // base case
        if (i == 9) return true;
        if (board[i][j] != '.') return dfs(board, i, j + 1);

        // try all choices
        for (int v = 1; v <= 9; ++v) {
            if (rused[i][v] || cused[j][v] || bused[(i / 3) * 3 + j / 3][v])
                continue;
            board[i][j] = '0' + v;
            rused[i][v] = cused[j][v] = bused[(i / 3) * 3 + j / 3][v] = true;
            if (dfs(board, i, j + 1)) return true;
            rused[i][v] = cused[j][v] = bused[(i / 3) * 3 + j / 3][v] = false;
            board[i][j] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        rused = cused = bused =
            vector<vector<bool>>(9, vector<bool>(10, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int v = board[i][j] - '0';
                if (v == '.' - '0') continue;
                rused[i][v] = cused[j][v] = bused[(i / 3) * 3 + j / 3][v] =
                    true;
            }
        }

        dfs(board, 0, 0);
    }
};

// soln 1: my soln

class Solution {
  public:
    vector<vector<bool>> rused, cused, bused;

    bool dfs(vector<vector<char>> &board, int i, int j) {
        // base case
        if (i == 9 && j == 0) return true;

        int nexi, nexj;
        (j + 1 <= 8) ? (nexi = i, nexj = j + 1) : (nexi = i + 1, nexj = 0);
        // note: (someValue ? (++x, ++y) : --x), --y;
        // https://stackoverflow.com/questions/47538906/why-does-the-ternary-operator-with-commas-evaluate-only-one-expression-in-the-tr/47538969#47538969

        if (board[i][j] != '.') {
            return dfs(board, nexi, nexj);
        } else if (board[i][j] == '.') {
            for (int v = 1; v <= 9; ++v) {
                if (rused[i][v] || cused[j][v] || bused[(i / 3) * 3 + j / 3][v])
                    continue;
                board[i][j] = (char)('0' + v);
                rused[i][v] = cused[j][v] = bused[(i / 3) * 3 + j / 3][v] =
                    true;
                if (dfs(board, nexi, nexj)) return true;
                rused[i][v] = cused[j][v] = bused[(i / 3) * 3 + j / 3][v] =
                    false;
                board[i][j] = '.';
            }
            return false;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        rused = cused = bused =
            vector<vector<bool>>(9, vector<bool>(10, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int v = board[i][j] - '0';
                if (v == '.' - '0') continue;
                rused[i][v] = cused[j][v] = bused[(i / 3) * 3 + j / 3][v] =
                    true;
            }
        }

        dfs(board, 0, 0);
    }
};