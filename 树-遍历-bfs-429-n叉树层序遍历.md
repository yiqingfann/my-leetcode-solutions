# [429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

**难度**：medium

**题目**：n叉树层序遍历

**思路**：bfs

**评价**：bfs

**实现**：

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (q.size()) {
            auto [u, l] = q.front();
            q.pop();
            if (l < ans.size()) ans[l].push_back(u->val);
            else ans.push_back({u->val});
            
            for (auto v : u->children) {
                q.push({v, l + 1});
            }
        }
        
        return ans;
    }
};
```