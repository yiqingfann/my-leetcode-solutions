// https://leetcode.com/contest/weekly-contest-304/problems/maximum-number-of-groups-entering-a-competition/

class Solution {
  public:
    int maximumGroups(vector<int> &grades) {
        int n = grades.size();
        int k = 1;

        while ((1 + k) * k / 2 <= n) k++;

        return k - 1;
    }
};