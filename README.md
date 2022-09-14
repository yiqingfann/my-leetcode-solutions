TODO: 总结板子+复杂度
TODO：草稿，正在探索最好的总结方式，所以结构很乱，命名也很乱，待整理

文件命名规则：类型-问题-算法-题号-名称.md

# 通用思路
1. 读题的同时做想象
2. 看数据范围推测复杂度
3. 举最小的例子模拟，想想我要找什么？
4. 先想暴力怎么做，然后再识别出模型优化
5. 实现细节先把一般情况完整考虑好，然后再考虑特殊情况

# 问题 & 思路

**LC1105：序列分组求最值 -> dp**

**问题**：有n本书，知道宽和高，还知道书架宽度，问怎么依次放入使得书架高度最小

**思路**：`可以看成是n本书的一个序列`，我要分割这个序列，每组都是满足宽度要求的书架的一层，每组都有一个高度，我要知道每组高度之和最小是多少。（reduce成序列问题模型，用dp解决）

状态表示：f[i]，从第1-i本书的所有分割方法的集合，总高度的最小值

状态计算：按照最后一组的开始位置j=i:1划分。$f[i] = min_{j=i:1}(f[j - 1] + max(h[j]:h[i]))$

**LC131：给字符串s，要分割成回文串的组合，求所有分割方法**

**思路**：暴力就是枚举所有可能的分割位置，然后检查是否全部都是回文。发现最坏的情况是指数的，比如"aaaa"，所以确定要用暴搜。对当前问题，需要枚举第一个分割点，检查是否是回文。

这里的问题是，想要快速知道s[i:j]是否是回文串。暴力就是线性扫描，可以用预处理优化。对于一个字符串s，s[i:j]是回文串 iff s[i] == s[j]并且s[i+1][j-1]是回文串。画矩阵确定枚举顺序先j后i。

**总结心得/问题模型**：
1. 如果问题最坏的结果是指数的，那么就用爆搜
2. 问题：快速判断s[i:j]是否回文 -> 算法：dp

**LC72：给字符串a，b。每次操作可以添加，删除，修改。最少多少次操作把a变b**

**思路**：很典型的一系列决策，minimize cost的问题，用dp解决。solution是一个操作序列，观察到不同操作是不会互相影响的，所以可以根据操作的位置进行排序。

状态表示：f[i][j]表示把a[1:i]变成b[1:j]的所有操作方案中，长度的最小值

状态计算：根据方案的最后一个操作分类，因为操作可以排序，所以最后一个操作一定是对i操作的。把a[1:i]变成b[1:j]最后一步可以：删除i，在i后面添加，修改i，啥都不干。

**总结心得/问题模型**：
1. 问题模型：优化问题（要做一系列决策得到max val或者min cost） -> 算法：dp/greedy
2. 优化问题在举例理解题目的时候，可以考虑最终的决策序列长什么样子

**LC1139：给01矩阵，问最大的由1围成的正方形面积**

**思路**：看到数据范围100，大概可以O(n^3)，先想暴力做法，正方形是由左上角坐标+边长决定的，所以可以枚举i,j,l，然后检查四条边上是不是全是1，这样就是O(n^4)。需要O(1)检查一个区域之和，可以用前缀和优化。大正方形sum-小正方形sum就是四条边之和了。

**总结心得/问题模型**：
1. 读完问题，想暴力之前，先看数据范围，推测复杂度，知道要优化多少
2. 问题模型：求数组/矩阵range sum -> 算法：前缀和

**LC688：马每一步随机走8个方向之一，走k步，问留在棋盘的概率**

**思路**：每一次是走8个方向之一的决策，一系列决策，问有多少种方案（方案和概率怎么联系？）的问题，dp解决。f[i][j][k]代表从位置ij，走k步留在棋盘的概率，就是八个方向f[x][y][k-1]/8的和

**总结心得/问题模型**：
1. 问题模型：求走到目标位置的方案数/概率 -> 算法：dp

**LC322：有不同单位的硬币，找零最少需要多少个硬币**

**思路**：总数看成背包大小，硬币看成物品，面值看成体积，1看成价值。所以变成了完全背包问题。时间优化，空间优化。

**总结心得/问题模型**：
1. 问题模型：完全背包问题 -> 算法：dp

**LC322：把一个数组分成k段，分数是每一段的平均值之和，求最小分数**

**思路**：答案是一系列分段位置的决策，求一个最小值，dp解决。f[i][j]代表考虑物品1到i，分成<=j段的所有方案里，分数最大的方案。按照最后一个决策分类，也就是最后一段的开始位置k可以是1到i。f[i][j] = max(f[k - 1][j - 1] + avg(a[k:i])) for all k = 1 to i

**总结心得/问题模型**：
1. 问题模型：优化问题（要做一系列决策得到max val或者min cost） -> 算法：dp/greedy

---

# 问题模型

## 背包问题模型

**识别**

问题：拿物品，在体积限制内，能拿的最大价值是多少

### 每件物品能拿0/1件（01背包问题）

### 问题：完全背包问题模型

**识别**
拿物品，在体积限制内，能拿的最大价值是多少，每件物品能拿无数件

**思路**  
状态表示：f[i][j]表示只考虑前i件物品，总体积<=j的所有方案中，最大价值  
状态计算：按照第i件物品拿0/1/2/.../k个来分类  
优化1：用f[i][j - v[i]]来优化时间（不用枚举k了）  
优化2：用滚动数组来优化空间  

**例子**  
279. n被写成平方和，最短要多少个数  
转化思路：n是背包大小，1,4,9,16是物品体积，1是物品价值，求最小价值

## 序列问题模型

### 最长上升子序列模型

**识别**
？？

**思路**
状态表示：f[i]是所有以i为结尾的上升子序列中，最长的长度
状态计算：按照上升子序列倒数第二位的位置k来分类，f[i] = max(f[k] + 1)
优化：发现这个枚举k的过程是瓶颈。对于正在处理的i，如果已知在i之前，长度为1,2,...,i-1的上升子序列末尾最小值，那么就能二分判断a[i]能挂在谁的后面了。在每个位置i上，维护这个信息。

**例子**
300. 最长上升子序列

### 

---

## 整体思路：先枚举，然后再优化

**84-直方图里，最大矩形面积**  
两种枚举思路：
1. 枚举矩形左上右下端点，找区间最小
2. 枚举矩形高度，找左右第一个比他低的位置（识别单调栈）

**85-01矩阵里，最大的由1组成的长方形**  
两种枚举思路：
1. 枚举矩形左上角和右下角位置，然后看里面是不是全1
2. 枚举矩形下边界，如果知道每个位置上面1的高度（识别dp），那就可以reduce成找直方图最大矩形面积问题


---
求最优解，搜索空间很大（指数）-> DP
**例子**  
1.   给定字符串，能否拆分成给定单词表，不限使用次数  
暴力思路：n-1个空隙，每个都可以选择是否split，然后检查每一段是否在单词表里。指数复杂度（识别dp）
状态表示：f[i]代表0-i这个字串所有合法分解方案的集合，数值是集合是否为空
状态计算：按照这个字符串最后一次split的位置k分类，看f[k+1:i]是否在字典里，再看f[k]是否能被合法分解

注意：因为要看看f[k+1:i]是否在字典里，而unordered map不能对字符串做O(1)的查找，所以需要字符串哈希。字符串哈希最方便的计算是不断的append，而这里是不断的prepend，所以不是很理想。需要考虑反过来思考dp，也就是f[i]代表f[i:n-1]能否被合法分解，然后按照这个字符串第一次split的位置分类。

## 小模型
求附近第一个比我大/小的数：单调栈

构造BST：枚举根节点，递归构造左右部分
```
96. 用1-n构造所有可能的BST的根结点
枚举根结点i从1到n，然后问题就变成了要知道1到i-1的所有可能根节点，以及要知道i+1到n的所有可能根节点，和原问题一样，可以递归处理
```

构造BST：BST的不同结构数量，只跟结点个数有关（比如用1-10构造BST，和2-11是一样的）
```
95. 用1-n构造所有可能的BST数量
状态表示：f[i]代表结点数为i的BST的所有不同构造方法的数量
状态转移：按照根左子树大小来分类。枚举左子树大小k=0,1,...,i-1，结果加上左子树数量*右子树数量
```




## 数学结论

四平方定理：正整数n一定能被写成4个平方数之和  
三平方定理：正整数n能被写成3个平方数之和 iff n != 4^a(8b+c)  
例子：279. n被写成平方和，最短要多少个数

## STL复杂度
unordered_set通常用来做hash，count是O(1)次的计算hash+compare。因此如果是字符串，其实需要O(len) 
https://www.appsloveworld.com/cplus/100/161/c-unordered-set-string-hash-time-complexity