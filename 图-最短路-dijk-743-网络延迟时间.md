# [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)

**难度**：medium

**题目**：求从一个点k出发，到所有点最短距离的最大值

**思路**：求k到所有点的最短距离，然后取max

**评价**：模版题。朴素dijkstra，堆优化dijkstra，spfa

**实现**：

```cpp
// soln 3: spfa

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // store graph
        typedef pair<int, int> pii;
        unordered_map<int, vector<pii>> nbs;
        for (auto e : times) {
            int u = e[0], v = e[1], w = e[2];
            nbs[u].push_back({w, v});
        }
        
        // run spfa
        queue<int> q;
        vector<bool> pending(n + 1, false);
        vector<int> dist(n + 1, 0x3f3f3f3f);
        
        q.push(k), dist[k] = 0, pending[k] = true;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            pending[u] = false;
            // relax all neighbors
            for (auto [w, v] : nbs[u]) {
                if (dist[u] + w >= dist[v]) continue;
                dist[v] = dist[u] + w;
                if (!pending[v]) q.push(v), pending[v] = true;
            }
        }
        
        // compute ans
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};

// soln 2: heap optimize

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // store graph
        typedef pair<int, int> pii;
        unordered_map<int, vector<pii>> nbs;
        for (auto e : times) {
            int u = e[0], v = e[1], w = e[2];
            nbs[u].push_back({v, w});
        }
        
        // compute shortest path
        vector<int> dist(n + 1, 0x3f3f3f3f), used(n + 1, false);
        priority_queue<pii, vector<pii>, greater<pii>> h;
        
        h.push({0, k});
        dist[k] = 0;
        while (h.size()) {
            auto [d, u] = h.top();
            h.pop();
            // lazy del
            if (used[u]) continue;
            // relax all neighbors
            for (auto [v, w] : nbs[u]) {
                if (dist[u] + w >= dist[v]) continue;
                dist[v] = dist[u] + w;
                h.push({dist[v], v});
            }
            used[u] = true;
        }
        
        // get ans
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};

// soln 1: vanilla
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build graph
        vector<vector<int>> g(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        for (auto e : times) {
            int u = e[0], v = e[1], w = e[2];
            g[u][v] = w;
        }
        
        // init dist
        vector<int> dist(n + 1, 0x3f3f3f3f), used(n + 1, false);
        dist[k] = 0;
        
        // compute dist
        for (int _ = 0; _ < n; ++_) {
            // find unused node t with min dist
            int t = -1;
            for (int i = 1; i <= n; ++i) {
                if (used[i]) continue;
                if (t == -1 || dist[i] < dist[t]) t = i;
            }
            
            // use t to relax neighbors
            for (int i = 1; i <= n; ++i) {
                dist[i] = min(dist[i], dist[t] + g[t][i]);
            }
            
            used[t] = true;
        }
        
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};
```