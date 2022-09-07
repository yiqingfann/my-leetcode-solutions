文件命名规则：类型-问题-算法-题号-名称.md

TODO: 总结板子+复杂度

## 整体思路：先枚举，然后再优化

**84-直方图里，最大矩形面积**  
两种枚举思路：
1. 枚举矩形左上右下端点，找区间最小
2. 枚举矩形高度，找左右第一个比他低的位置（识别单调栈）

**85-01矩阵里，最大的由1组成的长方形**  
两种枚举思路：
1. 枚举矩形左上角和右下角位置，然后看里面是不是全1
2. 枚举矩形下边界，如果知道每个位置上面1的高度（识别dp），那就可以reduce成找直方图最大矩形面积问题

## 基础问题模型

求最优解，搜索空间很大（指数）-> DP

求附近第一个比我大/小的数 -> 单调栈
