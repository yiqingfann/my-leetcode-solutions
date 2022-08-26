# [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)

**难度**：med

**题目**：给bst和一个目标值，删除对应节点

**思路**：找到要删的点，如果0个child，那么直接删除。如果1个child，短接。如果2个child，找到successor，覆盖当前值，删除successor。（predecessor也可）

**评价**：传入引用的话，如果调用的时候是把u->left当作新的u(u')，那修改u'相当于修改了u->left，这样可以直接修改parent的left了，没必要多传一个p参数。

**实现**：

```cpp
// soln 2: discuss 0 child, 1 child, 2 child

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void del(TreeNode *&u, int key) {
        if (!u) return;
        
        if (key < u->val) return del(u->left, key);
        if (key > u->val) return del(u->right, key);
        
        if (!u->left && !u->right) u = nullptr;
        else if (!u->left) u = u->right;
        else if (!u->right) u = u->left;
        else {
            // find successor
            auto t = u->right;
            while (t->left) t = t->left;
            u->val = t->val;
            del(u->right, t->val);
            // while (t->left && t->left->left) t = t->left;
            // if (t->left) u->val = t->left->val, t->left = t->left->right;
            // else u->val = t->val, u->right = t->right;
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;
    }
};

// soln 1: discuss has child / has no child

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *u, TreeNode *p, int key) {
        if (!u) return;
        
        if (key < u->val) return dfs(u->left, u, key);
        if (key > u->val) return dfs(u->right, u, key);
        
        if (u->left) {
            // find predecessor
            auto t = u->left;
            while (t->right && t->right->right) t = t->right;
            if (t->right) u->val = t->right->val, t->right = t->right->left;
            else u->val = t->val, u->left = t->left;
        } else if (u->right) {
            // find successor
            auto t = u->right;
            while (t->left && t->left->left) t = t->left;
            if (t->left) u->val = t->left->val, t->left = t->left->right;
            else u->val = t->val, u->right = t->right;
        } else {
            if (p->left == u) p->left = nullptr;
            else if (p->right == u) p->right = nullptr;
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key && !root->left && !root->right) return nullptr;
        dfs(root, nullptr, key);
        return root;
    }
};
```