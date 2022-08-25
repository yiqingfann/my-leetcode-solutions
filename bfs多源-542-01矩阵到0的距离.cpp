// https://leetcode.com/problems/01-matrix/


// soln: multi source bfs

typedef pair<int, int> pii;

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        // from all node 0 to node i, the min dist is the result -> do bfs for
        // each node 0 add a super source node connecting to all node 0 -> do
        // bfs for just super souce node
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // enque all node 0
        queue<pii> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        // expand each node
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (dist[a][b] != -1) continue;
                dist[a][b] = dist[x][y] + 1;
                q.push({a, b});
            }
        }

        return dist;
    }
};

// my soln (TLE): repeat

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        // init all zeros
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) dist[i][j] = 0;
            }
        }

        // at i th iter, dist = i + 1 is filled
        for (int r = 0; r < (n - 1) + (m - 1); ++r) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (dist[i][j] == 0) continue;
                    int t = INT_MAX;
                    for (int d = 0; d < 4; ++d) {
                        int a = i + dx[d], b = j + dy[d];
                        if (a < 0 || a >= n || b < 0 || b >= m) continue;
                        if (dist[a][b] == -1) continue;
                        t = min(t, dist[a][b]);
                    }
                    if (t != INT_MAX) dist[i][j] = t + 1;
                }
            }
        }

        return dist;
    }
};