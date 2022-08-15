// https://leetcode.com/contest/weekly-contest-304/problems/make-array-zero-by-subtracting-equal-amounts/

class Solution {
  public:
    int minimumOperations(vector<int> &nums) {
        unordered_set<int> s;

        for (auto n : nums) {
            if (n == 0) continue;
            s.insert(n);
        }

        return s.size();
    }
};