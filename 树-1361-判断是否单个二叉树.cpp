// https://leetcode.com/problems/validate-binary-tree-nodes/

class Solution {
  public:
    int tree_size(int root, vector<int> &l, vector<int> &r) {
        if (root == -1) return 0;
        return 1 + tree_size(l[root], l, r) + tree_size(r[root], l, r);
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                                 vector<int> &rightChild) {
        // check if there is
        // exactlty one node with in-degree = 0 (potential root)
        // all other nodes has in-degree = 1

        // compute in degree and make sure all <= 1
        vector<int> degin(n, 0);
        for (int i = 0; i < n; ++i) {
            int a = leftChild[i], b = rightChild[i];
            if (a != -1) {
                degin[a]++;
                if (degin[a] > 1) return false;
            }
            if (b != -1) {
                degin[b]++;
                if (degin[b] > 1) return false;
            }
        }

        // find potential root and make sure only one
        auto iter = find(degin.begin(), degin.end(), 0);
        if (iter == degin.end()) return false; // no in-degree = 0
        if (find(iter + 1, degin.end(), 0) != degin.end())
            return false; // multiple in-degree = 0

        // check the tree size of potential root == n
        // note: to avoid 0 -> 1, 2 -> 3 -> 2
        int root = iter - degin.begin();
        int siz = tree_size(root, leftChild, rightChild);

        return siz == n;
    }
};