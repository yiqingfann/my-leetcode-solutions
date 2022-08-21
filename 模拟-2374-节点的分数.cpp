// https://leetcode.com/problems/node-with-highest-edge-score/

class Solution {
  public:
    int edgeScore(vector<int> &edges) {
        int n = edges.size();
        vector<long long> scores(n, 0);

        // compute scores
        for (int cur = 0; cur < n; cur++) {
            int nex = edges[cur];
            scores[nex] += cur;
        }

        // find node with max score
        long long val = -1, id = -1;
        for (int i = 0; i < n; i++) {
            if (scores[i] > val) {
                val = scores[i];
                id = i;
            }
        }

        return id;
    }
};