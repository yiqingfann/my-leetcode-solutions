class Solution {
  public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
        int n = books.size();
        vector<int> f(n + 1, 1e8);
        f[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int w = 0, mh = 0;
            for (int j = i; j >= 1; --j) {
                w += books[j - 1][0], mh = max(mh, books[j - 1][1]);
                if (w > shelfWidth) break;
                f[i] = min(f[i], f[j - 1] + mh);
            }
        }
        return f[n];
    }
};