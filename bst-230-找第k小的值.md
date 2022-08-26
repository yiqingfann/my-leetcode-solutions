# [https://leetcode.com/problems/kth-smallest-element-in-a-bst/](230. Kth Smallest Element in a BST)

**难度**：med

**题目**：给二叉搜索树，找第k小的值

**思路**：in-order遍历，visit的时候counter++，等于k就记录当前节点数值作为ans

**评价**：全局变量counter和ans感觉不是很舒服

**实现**：

```cpp
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
    int cur, target, ans;
    
    bool dfs(TreeNode *u) {
        if (!u) return false;
        
        if(dfs(u->left)) return true;
        
        cur++;
        if (cur == target) {
            ans = u->val;
            return true;
        }
        
        return dfs(u->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        cur = 0, target = k, ans = -1;
        dfs(root);
        return ans;
    }
};
```