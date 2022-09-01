# [997. Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)

**难度**：easy

**题目**：n个人1-n，给a->b的信任关系，找唯一一个+不信任任何人+被所有其他人信任的人是谁

**思路**：记录in和out degree，遍历判断满足条件的人

**评价**：degree

**实现**：

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // compute out and in degrees
        vector<int> odeg(n + 1, 0), ideg(n + 1, 0);
        for (auto t : trust) {
            int a = t[0], b = t[1];
            odeg[a]++, ideg[b]++;
        }
        // check how many node with out = 0 and in = n - 1
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (odeg[i] == 0 && ideg[i] == n - 1) cnt++, ans = i;
        }
        
        return (cnt == 1) ? ans : -1;
    }
};
```