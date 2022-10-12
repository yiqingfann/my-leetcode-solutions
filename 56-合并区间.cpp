// https://leetcode.com/problems/merge-intervals/

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        /*
            1-------4
            1-----3
               2-------6
               2--3
                          8----10
                                    15-----18
            sort intervals wrt left
            check one by one
            maintain a st ed of the cur large interval: cur
            for each interval, decide if it shoud update cur or replace cur
        */

        // preprocess to sort intervals by left
        sort(intervals.begin(), intervals.end());

        // iterate through each interval, check update or replace cur
        int n = intervals.size();
        vector<int> cur(2, 0);
        cur[0] = intervals[0][0], cur[1] = intervals[0][1];

        vector<vector<int>> ans;
        for (int i = 1; i < n; ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            if (left <= cur[1]) {
                cur[1] = max(cur[1], right);
            } else {
                ans.push_back(cur);
                cur[0] = left, cur[1] = right;
            }
        }
        ans.push_back(cur);
        return ans;
    }
};