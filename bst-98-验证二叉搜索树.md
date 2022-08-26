# [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

**难度**：medium

**题目**：给一棵二叉树，验证是否是二叉搜索树

**思路**：要判断val比整个left都大，比整个right都小，所以只要dfs返回当前这棵树的最大最小值就行了。每个节点返回三个数值：是否合法BDT，min，max。

**评价**：忘了定义也没仔细看题，直接写了个dfs判断val比left大比right小，交了才发现错了。

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<int> dfs(TreeNode *u) {
        // res[0]: if this tree is valied
        // res[1]: min val in this tree
        // res[2]: max val in this tree
        vector<int> res = {1, u->val, u->val};

        if (u->left) {
            auto t = dfs(u->left);
            if (!t[0] || t[2] >= u->val) res[0] = 0;
            res[1] = min(res[1], t[1]);
            res[2] = max(res[2], t[2]);
        }

        if (u->right) {
            auto t = dfs(u->right);
            if (!t[0] || t[1] <= u->val) res[0] = 0;
            res[1] = min(res[1], t[1]);
            res[2] = max(res[2], t[2]);
        }

        return res;
    }

    bool isValidBST(TreeNode *root) {
        return dfs(root)[0];
    }
};
```