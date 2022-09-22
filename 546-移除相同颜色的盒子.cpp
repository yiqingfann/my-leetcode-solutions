class Solution {
  public:
    int removeBoxes(vector<int> &boxes) {
        int n = boxes.size();
        const int INF = 0x3f3f3f3f;
        vector<vector<vector<int>>> f(
            n, vector<vector<int>>(n, vector<int>(n + 1, -INF)));
        vector<vector<int>> g(n, vector<int>(n, -INF));

        // init state
        for (int i = 0; i < n; ++i) f[i][i][1] = 1, g[i][i] = 1;

        // compute state
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                for (int k = 1; k <= len; ++k) {
                    if (k == 1) f[i][j][k] = g[i + 1][j] + 1;
                    else {
                        for (int u = i + 1; u <= j - k + 2; ++u) {
                            if (boxes[u] != boxes[i]) continue;
                            int t = 0;
                            if (i + 1 <= u - 1) t = g[i + 1][u - 1];
                            f[i][j][k] =
                                max(f[i][j][k], t + f[u][j][k - 1] -
                                                    (k - 1) * (k - 1) + k * k);
                        }
                    }
                    g[i][j] = max(g[i][j], f[i][j][k]);
                }
            }
        }

        return g[0][n - 1];
    }
};