// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        // BFS, use queue
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size()) {
            // pop all nodes of this level and expand
            int rep = q.size();
            vector<int> res;
            while (rep--) {
                // pop the node, add to result
                auto t = q.front();
                q.pop();
                res.push_back(t->val);
                // add its children
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ans.push_back(res);
        }

        return ans;
    }
};