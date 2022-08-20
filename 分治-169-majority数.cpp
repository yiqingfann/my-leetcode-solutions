// https://leetcode.com/problems/majority-element/

// soln 1: O(1) space

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int val = -1, cnt = 0;

        for (auto x : nums) {
            if (cnt == 0) val = x, cnt = 1;
            else (x == val) ? cnt++ : cnt--;
        }

        return val;
    }
};

// soln 2: O(n) space

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();

        int ans = -1;
        unordered_map<int, int> cnt;
        for (auto v : nums) {
            cnt[v]++;
            if (cnt[v] > n / 2) {
                ans = v;
                break;
            }
        }

        return ans;
    }
};