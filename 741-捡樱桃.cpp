

// greedy dp, WA

typedef pair<int, int> pii;

class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        // f[i][j]
        // meaning: the max value of all possible paths to i, j
        // compute: f[i][j] = v[i][j] + max(f[i - 1][j], f[i][j - 1]) if exist
        // and reachable init: 0

        int n = grid.size();
        vector<vector<int>> f1(n, vector<int>(n, 0));
        vector<vector<pii>> prev(n, vector<pii>(n, {-1, -1}));

        // init state
        f1[0][0] = grid[0][0];
        prev[0][0] = {0, 0};
        // compute state
        const pii dir1[2] = {{-1, 0}, {0, -1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto [di, dj] : dir1) {
                    int x = i + di, y = j + dj;
                    if (x < 0 || x > n - 1 || y < 0 || y > n - 1) continue;
                    if (grid[x][y] == -1) continue;
                    if (prev[x][y] == pii({-1, -1})) continue;
                    if (f1[x][y] + grid[i][j] > f1[i][j]) {
                        f1[i][j] = f1[x][y] + grid[i][j];
                        prev[i][j] = {x, y};
                    }
                }
            }
        }

        // check solution exists
        if (prev[n - 1][n - 1] == pii({-1, -1})) return 0;

        // clear cells along the road
        for (int i = n - 1, j = n - 1; !(i == 0 && j == 0);) {
            grid[i][j] = 0;
            auto [x, y] = prev[i][j];
            i = x, j = y;
        }
        grid[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << " \n"[j == n - 1];
            }
        }

        vector<vector<int>> f2(n, vector<int>(n, 0));
        const pii dir2[2] = {{1, 0}, {0, 1}};
        // compute state
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                for (auto [di, dj] : dir2) {
                    int x = i + di, y = j + dj;
                    if (x < 0 || x > n - 1 || y < 0 || y > n - 1) continue;
                    if (grid[x][y] == -1) continue;
                    if (f2[x][y] + grid[i][j] > f2[i][j]) {
                        f2[i][j] = f2[x][y] + grid[i][j];
                    }
                }
            }
        }

        return f1[n - 1][n - 1] + f2[0][0];
    }
};