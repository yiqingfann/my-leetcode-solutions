// https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        // sort meetings by begin time
        // simulate the process
        // use a min heap to maintain all ongoing meetings
        // when a new meeting need to be schedule, pop all ended meetings and
        // add this one min number of room required is the max heap size along
        // the process

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> mh;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            while (mh.size() && mh.top() <= l) mh.pop();
            mh.push(r);
            ans = max(ans, (int)mh.size());
        }
        return ans;
    }
};