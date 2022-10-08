// https://leetcode.com/problems/knight-dialer/

// soln 2

const int MOD = 1e9 + 7;

class Solution {
  public:
    int knightDialer(int n) {
        // f[i][j]
        // meaning: the number of all possible sequences, starting with number
        // i, using j jumps compute: for all valid detination k, sum up f[k][j -
        // 1] init: f[][0] = 1 ans: f[0][n - 1] + f[1][n - 1] + ... + f[9][n -
        // 1]

        // init state
        vector<vector<int>> f(10, vector<int>(n, 0));
        for (int i = 0; i < 10; ++i) {
            f[i][0] = 1;
        }

        // compute state
        vector<vector<int>> nex = {
            {4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
            {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4},
        };
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < 10; ++i) {
                for (auto k : nex[i]) {
                    f[i][j] = (f[i][j] + f[k][j - 1]) % MOD;
                }
            }
        }

        // get ans
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans = (ans + f[i][n - 1]) % MOD;
        }
        return ans;
    }
};

// soln 1
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;

class Solution {
  public:
    pii getPos(int x) {
        if (x == 0) return {3, 1};
        return {(x - 1) / 3, (x - 1) % 3};
    }

    int getNum(int i, int j) {
        if (i == 3 && j == 1) return 0;
        return i * 3 + j + 1;
    }

    int knightDialer(int n) {
        // f[i][j]
        // meaning: the number of all possible sequences, starting with number
        // i, using j jumps compute: for all valid detination k, sum up f[k][j -
        // 1] init: f[][0] = 1 ans: f[0][n - 1] + f[1][n - 1] + ... + f[9][n -
        // 1]

        // init state
        vector<vector<int>> f(10, vector<int>(n, 0));
        for (int i = 0; i < 10; ++i) {
            f[i][0] = 1;
        }

        // compute state
        const pii dir[8] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                            {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < 10; ++i) {
                auto [x, y] = getPos(i);
                for (auto [dx, dy] : dir) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a > 3 || b < 0 || b > 2) continue;
                    if (a == 3 && b == 0 || a == 3 && b == 2) continue;
                    int k = getNum(a, b);
                    f[i][j] = (f[i][j] + f[k][j - 1]) % MOD;
                }
            }
        }

        // get ans
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans = (ans + f[i][n - 1]) % MOD;
        }
        return ans;
    }
};