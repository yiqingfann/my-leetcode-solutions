typedef long long ll;

class Solution {
  public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        ll posum = 0;
        for (auto &t : transactions) {
            int a = t[0], b = t[1];
            if (a - b > 0) posum += a - b;
        }

        ll ans = 0;
        for (auto &t : transactions) {
            ll a = t[0], b = t[1];
            ll u = posum;
            if (a - b > 0) u -= a - b;
            ans = max(ans, u + a);
        }

        return ans;
    }
};