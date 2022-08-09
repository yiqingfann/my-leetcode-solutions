// https://leetcode.com/problems/binary-tree-preorder-traversal/

// soln 1: dfs

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
    vector<int> ans;

    void dfs(TreeNode *cur) {
        if (!cur) return;
        ans.push_back(cur->val);
        dfs(cur->left);
        dfs(cur->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }
};

// soln 2: stack

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> stk;

        auto cur = root;
        while (cur || stk.size()) {
            while (cur) {
                ans.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(), stk.pop();
            cur = cur->right;
        }

        return ans;
    }
};