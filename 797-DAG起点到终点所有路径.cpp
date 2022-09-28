// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
  public:
    int n;
    vector<vector<int>> g;
    vector<int> path;
    vector<vector<int>> ans;

    void dfs(int u) {
        // add to path
        path.push_back(u);

        // base case
        if (u == n - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        // enumerate all next steps
        for (auto v : g[u]) {
            dfs(v);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        n = graph.size();
        g = graph;
        // dfs from 0, if reach n - 1 add path to ans
        dfs(0);
        // return ans
        return ans;
    }
};