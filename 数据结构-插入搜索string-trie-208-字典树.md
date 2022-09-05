# [208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

**难度**：medium

**题目**：实现trie类，支持insert，search，prefix操作

**思路**：trie，但是按照基础课板子用array会MLE，用struct+pointer实现才行

**评价**：trie

**实现**：

```cpp
// soln 1: trie with struct + pointer

class Trie {
public:
    struct Node {
        Node *children[26];
        int cnt;
        Node() {
            for (auto &c : children) c = nullptr;
            cnt = 0;
        }
    } *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto cur = root;
        for (auto c : word) {
            int t = c - 'a';
            if (!cur->children[t]) cur->children[t] = new Node();
            cur = cur->children[t];
        }
        cur->cnt = 1;
    }
    
    bool search(string word) {
        auto cur = root;
        for (auto c : word) {
            int t = c - 'a';
            if (!cur->children[t]) return false;
            cur = cur->children[t];
        }
        return cur->cnt;
    }
    
    bool startsWith(string prefix) {
        auto cur = root;
        for (auto c : prefix) {
            int t = c - 'a';
            if (!cur->children[t]) return false;
            cur = cur->children[t];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// MLE: trie with array

const int N = 6e7 + 10;

class Trie {
public:
    int son[N][26] = {0}, cnt[N] = {0}, idx = 0;
    
    Trie() {
        
    }
    
    void insert(string word) {
        int cur = 0;
        for (auto c : word) {
            int t = c - 'a';
            if (!son[cur][t]) son[cur][t] = ++idx;
            cur = son[cur][t];
        }
        cnt[cur]++;
    }
    
    bool search(string word) {
        int cur = 0;
        for (auto c : word) {
            int t = c - 'a';
            if (!son[cur][t]) return false;
            cur = son[cur][t];
        }
        return cnt[cur] != 0;
    }
    
    bool startsWith(string prefix) {
        int cur = 0;
        for (auto c : prefix) {
            int t = c - 'a';
            if (!son[cur][t]) return false;
            cur = son[cur][t];
        }
        
        if (cnt[cur] != 0) return true;
        for (int i = 0; i < 26; ++i) {
            if (son[cur][i] != 0) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```