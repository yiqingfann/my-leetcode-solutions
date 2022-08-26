# [501. Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

**难度**：easy

**题目**：给bst，left<=val<=right，找所有的众数

**思路**：想想成在遍历升序数组的时候找众数，那么就是看看当前这个数有多少个了，超过了历史最高那他就是历史最高，等于的话并列最高。

**评价**：核心就是把bst看成升序数组来思考解法

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
    int last, cnt, mcnt;
    vector<int> ans;
    
    void dfs(TreeNode *u) {
        // base case
        if (!u) return;
        
        dfs(u->left);
        
        // visit u
        // maintain cnt
        if (u->val == last) cnt++;
        else cnt = 1;
        // update mcnt and ans
        if (cnt > mcnt) mcnt = cnt, ans = { u->val };
        else if (cnt == mcnt) ans.push_back(u->val);
        // update last
        last = u->val;
        
        dfs(u->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        cnt = mcnt = 0;
        last = -1e9;
        dfs(root);
        return ans;
    }
};
```