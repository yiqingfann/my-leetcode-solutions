// https://leetcode.com/contest/weekly-contest-304/problems/find-closest-node-to-given-two-nodes/

class Solution {
  public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {

        int n = edges.size();
        vector<int> d1(n, -1), d2(n, -1);

        d1[node1] = d2[node2] = 0;

        // compute distance start from node1
        int cur = node1, nex = edges[cur];
        while (nex != -1) {
            if (d1[nex] != -1) break;
            d1[nex] = d1[cur] + 1;
            cur = nex, nex = edges[cur];
        }
        // compute distance start from node2
        cur = node2, nex = edges[cur];
        while (nex != -1) {
            if (d2[nex] != -1) break;
            d2[nex] = d2[cur] + 1;
            cur = nex, nex = edges[cur];
        }

        // compute result
        int val = INT_MAX, id = -1;
        for (int i = 0; i < n; i++) {
            int a = d1[i], b = d2[i];
            if (a == -1 || b == -1) continue;
            if (max(a, b) < val) {
                val = max(a, b);
                id = i;
            }
        }

        return id;
    }
};