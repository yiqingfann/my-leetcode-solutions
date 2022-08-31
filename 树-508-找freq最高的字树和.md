# [508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)

**难度**：medium

**题目**：给一棵树，求频率最高的subtree sum

**思路**：dfs求每个subtree的sum，同时更新freq和答案

**评价**：

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
    vector<int> ans;
    unordered_map<int, int> freq;
    int mfreq;
    
    int dfs(TreeNode *u) {
        if (!u) return 0;
        int csum = u->val + dfs(u->left) + dfs(u->right);
        freq[csum]++;
        if (freq[csum] > mfreq) {
            ans = { csum };
            mfreq = freq[csum];
        } else if (freq[csum] == mfreq) {
            ans.push_back(csum);
        }
        return csum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        ans = vector<int>();
        freq = unordered_map<int, int>();
        mfreq = 0;
        
        dfs(root);
        return ans;
    }
};
```