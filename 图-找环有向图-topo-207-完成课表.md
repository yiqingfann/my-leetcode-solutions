# [207. Course Schedule](https://leetcode.com/problems/course-schedule/)

**难度**：medium

**题目**：给编号0-n-1的课，以及所有b->a的先修关系，问能否完成课表

**思路**：b->a的边，判断有没有环

**评价**：topo sort

**实现**：

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> deg(n, 0);
        unordered_map<int, set<int>> nbs;
        
        // topo sort
        for (auto v : prerequisites) {
            deg[v[0]]++;
            nbs[v[1]].insert(v[0]);
        }
        
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) q.push(i);
        }
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt++;
            for (auto u : nbs[t]) {
                deg[u]--;
                if (deg[u] == 0) q.push(u);
            }
        }
        
        return cnt == n;
    }
};
```