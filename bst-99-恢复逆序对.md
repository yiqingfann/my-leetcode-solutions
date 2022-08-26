# [https://leetcode.com/problems/recover-binary-search-tree/](99. Recover Binary Search Tree)

**难度**：med

**题目**：给一个bst，里面有一对node的数值被交换了，恢复他们

**思路**：空间O(n)做法：in-order遍历，找到逆序的pair。如果有两个pair，交换第一组第一个和第二组第二个。如果有一个pair，交换他们两个。空间O(1)做法：in-order morris遍历。

**评价**：

**实现**：

```cpp

// soln 2: O(1) space with morris

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
    void recoverTree(TreeNode* root) {
        TreeNode *p1 = nullptr, *p2 = nullptr, *last = nullptr;
        auto cur = root;
        while (cur) {
            if (cur->left) {
                // find predecessor
                auto t = cur->left;
                while (t->right && t->right != cur) t = t->right;
                // if arrive at cur from top
                if (!t->right) {
                    t->right = cur;
                    // goto left
                    cur = cur->left;
                }
                // if arrive at cur from pred
                else {
                    t->right = nullptr;
                    // visit cur
                    if (last && last->val >= cur->val) {
                        if (!p1) p1 = last, p2 = cur;
                        else p2 = cur;
                    }
                    last = cur;
                    // goto right
                    cur = cur->right;
                }
            } else if (!cur->left) {
                // visit cur
                if (last && last->val >= cur->val) {
                    if (!p1) p1 = last, p2 = cur;
                    else p2 = cur;
                }
                last = cur;
                // goto right
                cur = cur->right;
            }
        }
        swap(p1->val, p2->val);
    }
};

// soln 1: O(n) space

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
    TreeNode *lastNode;
    
    TreeNode *p1, *p2, *p3, *p4;
    
    void dfs(TreeNode *u) {
        if (!u) return;
        
        dfs(u->left);
        if (lastNode && lastNode->val > u->val) {
            if (!p1) p1 = lastNode, p2 = u;
            else p3 = lastNode, p4 = u;
        }
        lastNode = u;
        dfs(u->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        int t;
        if (p3) t = p1->val, p1->val = p4->val, p4->val = t;
        else t = p1->val, p1->val = p2->val, p2->val = t;
    }
};

```