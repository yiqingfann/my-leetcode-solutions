// https://leetcode.com/problems/number-of-ships-in-a-rectangle/

// soln 2: divide and conquer

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
  public:
    int dfs(Sea &sea, vector<int> topRight, vector<int> bottomLeft) {
        int x1 = topRight[0], y1 = topRight[1];
        int x2 = bottomLeft[0], y2 = bottomLeft[1];

        // base case
        if (!(x1 >= x2 && y1 >= y2)) return 0;
        if (!sea.hasShips({x1, y1}, {x2, y2})) return 0;
        if (x1 == x2 && y1 == y2) return 1;

        // build result from smaller results
        int x = (x1 + x2) >> 1, y = (y1 + y2) >> 1;
        return dfs(sea, {x, y}, {x2, y2}) + dfs(sea, {x, y1}, {x2, y + 1}) +
               dfs(sea, {x1, y1}, {x + 1, y + 1}) +
               dfs(sea, {x1, y}, {x + 1, y2});
    }

    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        // if divide the rect into four smaller rect
        // then the ans is the sum of res of those four
        return dfs(sea, topRight, bottomLeft);
    }
};

// soln 1: binary search

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
  public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        // each boat has x and y vals
        // find the smallest x with binary search
        //     on that vertical line, find the smallest y with binary search
        //     repeat for all y
        // repeat for all x

        int ans = 0;
        int x1 = bottomLeft[0], y1 = bottomLeft[1];
        int x2 = topRight[0], y2 = topRight[1];

        int lx = x1, rx = x2;
        while (lx <= rx) {
            int sx = lx;
            while (lx < rx) {
                int mx = (lx + rx) >> 1;
                if (sea.hasShips({mx, y2}, {sx, y1})) rx = mx;
                else lx = mx + 1;
            }
            if (sea.hasShips({rx, y2}, {rx, y1})) {
                int ly = y1, ry = y2;
                while (ly <= ry) {
                    int sy = ly;
                    while (ly < ry) {
                        int my = (ly + ry) >> 1;
                        if (sea.hasShips({rx, my}, {rx, sy})) ry = my;
                        else ly = my + 1;
                    }
                    if (sea.hasShips({rx, ry}, {rx, ry})) ++ans;
                    ly += 1, ry = y2;
                }
            }
            lx += 1, rx = x2;
        }
        return ans;
    }
};