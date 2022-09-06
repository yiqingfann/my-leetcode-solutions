# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

**难度**：medium

**题目**：给数列，求最大的字串和

**思路**：最简单就是dp，f[i]代表以i为结尾的所有字串里的max值。如果f[i - 1]>0那么就用它，不然就不用它。注意输入0-index，f改成1-index。

然后是用分治思想，虽然空间会差一点，但是好像是线段树问题的一个字问题，以后支持修改后再查询会用到，所以还是学了一下。大概思想就是，

当前这个区间的最大子串和，可能是全部在左半边（左半边的最大字串和），可能是全部在右半边（右半边的最大字串和），可能横跨两个段（左半边的最大后缀和+右半边的最大前缀和）。

然后因为是分治问题，我当前区间也要求最大前缀和和最大后缀和。对于当前区间的最大前缀和，可能是全在左半边（左半边最大前缀和），可能横跨左右（左半边总和+右半边最大前缀和）。最大后缀和是一样的。

再因为是分治问题，我当前区间也要求总和，等于左右半边总和相加。

这道题分析分治需要返回什么量很经典，值得复习题解。总的来说，就是写下左右和当前，然后看当前的量需要什么，在左和右写下来，然后三个都同步一下。然后继续看当前的量需要什么，直到能被左右当前有的东西满足。

--当前需要最大字串和，因此需要左右的：--
当前：最大字串和
左：最大子串和，最大后缀
右：最大子串和，最大前缀

--同步--
当前：最大子串和，最大前缀，最大后缀
左：最大子串和，最大前缀，最大后缀
右：最大子串和，最大前缀，最大后缀

--当前需要最大前缀，因此需要左右的：--
当前：最大子串和，最大前缀，最大后缀
左：最大子串和，最大前缀，最大后缀，总和
右：最大子串和，最大前缀，最大后缀

--同步--
当前：最大子串和，最大前缀，最大后缀，总和
左：最大子串和，最大前缀，最大后缀，总和
右：最大子串和，最大前缀，最大后缀，总和

--当前需要最大后缀，因此需要左右的：--
当前：最大子串和，最大前缀，最大后缀，总和
左：最大子串和，最大前缀，最大后缀，总和
右：最大子串和，最大前缀，最大后缀，总和

--都有了，无变化，不需要同步--

--当前需要总和，因此需要左右的：--
当前：最大子串和，最大前缀，最大后缀，总和
左：最大子串和，最大前缀，最大后缀，总和
右：最大子串和，最大前缀，最大后缀，总和

--都有了，无变化，不需要同步--

--全部都满足了，这就是当前需要返回的所有量--

**评价**：dp

**实现**：

```cpp

// soln 3: divide and conqur O(n) time, O(logn) space

class Solution {
public:
    struct Info {
      int msum, mlsum, mrsum, tsum;  
    };
    
    Info dfs(vector<int> &nums, int l, int r) {
        // base case
        if (l == r) return {nums[l], nums[l], nums[l], nums[l]};
        
        // general case
        int mid = (l + r) >> 1;
        auto lres = dfs(nums, l, mid), rres = dfs(nums, mid + 1, r);
        Info res;
        res.msum = max(max(lres.msum, rres.msum), lres.mrsum + rres.mlsum);
        res.mlsum = max(lres.mlsum, lres.tsum + rres.mlsum);
        res.mrsum = max(rres.mrsum, rres.tsum + lres.mrsum);
        res.tsum = lres.tsum + rres.tsum;
        return res;
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        auto res = dfs(nums, 0, n - 1);
        return res.msum;
    }
};

// soln 2: rolling to optimize space O(n) time, O(1) space

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 1, last = 0; i <= n; ++i) {
            int cur = max(last + nums[i - 1], nums[i - 1]);
            ans = max(ans, cur);
            last = cur;
        }
        return ans;
    }
};

// soln 1: vanilla

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        int ans = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]);
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
```