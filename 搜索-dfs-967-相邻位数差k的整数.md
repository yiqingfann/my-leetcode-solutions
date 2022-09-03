# [967. Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)

**难度**：medium

**题目**：求位数为n，相邻数字绝对值差k的所有非负整数

**思路**：暴搜

**评价**：dfs

**实现**：

```cpp
// soln 2: int state

class Solution {
public:
    vector<int> ans;
    
    void dfs(int pos, int cur, int n, int k) {
        // base case
        if (pos == n) {
            ans.push_back(cur);
            return;
        }
        
        // general case
        int last = cur % 10;
        if (last - k >= 0) dfs(pos + 1, cur * 10 + last - k, n, k);
        if (k && last + k <= 9) dfs(pos + 1, cur * 10 + last + k, n, k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        // enumerate first digit
        for (int i = 1; i <= 9; ++i) {
            dfs(1, i, n, k);
        }
        return ans;
    }
};

// soln 1: string state

class Solution {
public:
    vector<int> ans;
    
    void dfs(int pos, string cur, int n, int k) {
        // base case
        if (cur.size() == n) {
            ans.push_back(stoi(cur));
            return;
        }
                
        // general case
        char last = cur[pos - 1];
        char c1 = last - k, c2 = last + k;
        if (c1 >= '0') dfs(pos + 1, cur + c1, n, k);
        if (c1 != c2 && c2 <= '9') dfs(pos + 1, cur + c2, n, k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        // enumerate position 0
        for (int i = 1; i <= 9; ++i) {
            dfs(1, to_string(i), n, k);
        }
        
        return ans;
    }
    
    // n = 3, k = 7
    // pos = 1, cur = "1"
        // pos = 2, cur = "18"
            // pos == 3, cur = "181"
    
};
```