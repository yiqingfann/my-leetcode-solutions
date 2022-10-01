// https://leetcode.com/problems/two-city-scheduling/

// soln 2

class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] - a[1] < b[0] - b[1];
        });

        int m = costs.size(), n = m / 2;
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += costs[i][0];
        for (int i = n; i < m; ++i) ans += costs[i][1];
        return ans;
    }
};

// soln 1

class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        // first, do it in a greedy way, choose the min for each person
        // then if na == n, done
        // if na > n, (na - n) people has to switch to b. choose those with min
        // cb - ca if na < n, similar
        int ans = 0;
        int m = costs.size(), n = m / 2;
        priority_queue<int, vector<int>, greater<int>> ha, hb;
        int cnta = 0, cntb = 0;
        for (int i = 0; i < m; ++i) {
            int costa = costs[i][0], costb = costs[i][1];
            if (costa <= costb) {
                ans += costa;
                ha.push(costb - costa);
                cnta++;
            } else {
                ans += costb;
                hb.push(costa - costb);
                cntb++;
            }
        }

        // compare cnta and n and do modification
        while (cnta > n) {
            ans += ha.top(), ha.pop();
            cnta--, cntb++;
        }

        while (cntb > n) {
            ans += hb.top(), hb.pop();
            cntb--, cnta++;
        }

        return ans;
    }
};