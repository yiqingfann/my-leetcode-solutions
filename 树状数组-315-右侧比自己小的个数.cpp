// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
  public:
    const int N = 2e4 + 10;
    vector<int> tr;

    Solution() : tr(N, 0) {}

    int lowbit(int x) {
        return x & -x;
    }

    int psum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    void add(int x, int v) {
        for (int i = x; i <= N; i += lowbit(i)) tr[i] += v;
    }

    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = nums.size() - 1; i >= 0; --i) {
            int x = nums[i] + 1e4 + 1;
            ans[i] = psum(x - 1);
            add(x, 1);
        }

        return ans;
    }
};