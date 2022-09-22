// https://leetcode.com/problems/binary-tree-postorder-traversal/

// solution 2: stack

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
    vector<int> postorderTraversal(TreeNode *root) {
        // left, right, cur -> cur, right, left
        vector<int> ans;
        auto cur = root;
        stack<TreeNode *> stk;

        while (cur || stk.size()) {
            while (cur) {
                ans.push_back(cur->val);
                stk.push(cur);
                cur = cur->right;
            }

            cur = stk.top(), stk.pop();
            cur = cur->left;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// solution 1: dfs

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

    void dfs(TreeNode *u) {
        if (!u) return;

        dfs(u->left);
        dfs(u->right);
        ans.push_back(u->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }
};