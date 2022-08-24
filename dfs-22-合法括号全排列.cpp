// https://leetcode.com/problems/generate-parentheses/

// soln 2: pass state
// note: pass state whenerver possible, no need to recover state!

class Solution {
  public:
    vector<string> ans;

    void dfs(int pos, int lused, int lrem, int rused, int rrem, string state) {
        // base case
        if (pos == lused + lrem + rused + rrem) {
            ans.push_back(state);
            return;
        }

        // all choice for this position
        if (lrem) dfs(pos + 1, lused + 1, lrem - 1, rused, rrem, state + '(');
        if (rrem && lused > rused)
            dfs(pos + 1, lused, lrem, rused + 1, rrem - 1, state + ')');
    }

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, 0, n, "");
        return ans;
    }
};

// soln 1: global state

class Solution {
  public:
    vector<string> ans;
    string state;

    void dfs(int pos, int lused, int lrem, int rused, int rrem) {
        // base case
        if (pos == lused + lrem + rused + rrem) {
            ans.push_back(state);
            return;
        }

        // all choice for this position
        if (lrem) {
            state[pos] = '(';
            dfs(pos + 1, lused + 1, lrem - 1, rused, rrem);
            state[pos] = ' ';
        }

        if (rrem && lused > rused) {
            state[pos] = ')';
            dfs(pos + 1, lused, lrem, rused + 1, rrem - 1);
            state[pos] = ' ';
        }
    }

    vector<string> generateParenthesis(int n) {
        state = string(2 * n, ' ');
        dfs(0, 0, n, 0, n);
        return ans;
    }
};