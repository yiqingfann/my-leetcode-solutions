// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // base case
        // if two both null, they are the same
        // if one not null and one null, they are different
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;

        // build result from smaller results
        // tree p and q are same if
        // 1. p->val == q->val
        // 2. p left tree same as q left tree
        // 3. p right tree same as q right tree
        return (p->val == q->val && isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};