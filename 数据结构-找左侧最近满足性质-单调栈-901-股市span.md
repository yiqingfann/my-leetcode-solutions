# [901. Online Stock Span](https://leetcode.com/problems/online-stock-span/)

**难度**：medium

**题目**：给一系列数，问每个数左侧连续<=他本身的最大长度是多少

**思路**：其实就是对每个数，问左侧最近的一个>他的数位置在哪。单调栈里存有用的数的下标。

**评价**：单调栈

**实现**：

```cpp
class StockSpanner {
public:
    stack<int> stk;
    vector<int> prices;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int n = prices.size();
        while (stk.size() && prices[stk.top()] <= price) stk.pop();
        int ans = stk.size() ? n - 1 - stk.top() : n;
        stk.push(n - 1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```