# [139. Word Break](https://leetcode.com/problems/word-break/)

**难度**：medium

**题目**：

**思路**：

**评价**：

**实现**：

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        typedef unsigned long long ull;
        const int P = 131;
        
        unordered_set<ull> h;
        for (auto w : wordDict) {
            ull t = 0;
            for (auto c : w) {
                t = t * P + c;
            }
            h.insert(t);
        }
        
        int n = s.size();
        vector<bool> f(n + 1, false);
        f[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            ull t = 0;
            for (int j = i; j < n; ++j) {
                t = t * P + s[j];
                if (h.count(t) && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};
```