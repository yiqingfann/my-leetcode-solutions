# [684. Redundant Connection](https://leetcode.com/problems/redundant-connection/)

**难度**：medium

**题目**：原本是一颗undirected tree，加了一条边于是多了一个环。找到环上的一条边。

**思路**：从没有边开始，每次加边(u,v)，如果u, v本来就是连通的，那么这条边就构成了环

**评价**：union find

**实现**：

```cpp
class Solution {
public:
    vector<int> p;
    
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p = vector<int>(n + 1, -1);
        for (int i = 1; i <= n; ++i) p[i] = i;
        
        for (auto e : edges) {
            int a = e[0], b = e[1];
            int pa = find(a), pb = find(b);
            if (pa == pb) return e;
            p[pa] = pb;
        }
        
        return {};
    }
};
```