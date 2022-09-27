// https://leetcode.com/problems/number-of-islands/

class Solution {
  public:
    vector<vector<bool>> visited;
    vector<vector<char>> g;
    int n, m;

    void dfs(int x, int y) {
        // mark the island containing (x, y) as visited
        visited[x][y] = true;

        typedef pair<int, int> pii;
        const pii dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < 4; ++i) {
            auto [dx, dy] = dir[i];
            int a = x + dx, b = y + dy;
            if (a < 0 || a > n - 1 || b < 0 || b > m - 1) continue;
            if (g[a][b] == '0') continue;
            if (visited[a][b]) continue;
            dfs(a, b);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        // idea: flood fill, each time visit an island with dfs, increase the
        // count

        int ans = 0;
        n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        g = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                if (visited[i][j]) continue;
                dfs(i, j);
                ans++;
            }
        }

        return ans;
    }
};