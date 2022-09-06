# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

**难度**：easy

**题目**：每次可以走1或2步，问从0走到第n个台阶有多少种方法

**思路**：f[i] = f[i - 1] + f[i - 2]

**评价**：dp

**实现**：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};
```