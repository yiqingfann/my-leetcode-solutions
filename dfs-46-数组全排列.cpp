// https://leetcode.com/problems/permutations/

// soln 2: minor improve

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> state;
    vector<bool> used;

    void dfs(vector<int> &nums, int pos) {
        // base case
        if (pos == nums.size()) {
            ans.push_back(state);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            state.push_back(nums[i]), used[i] = true;
            dfs(nums, pos + 1);
            state.pop_back(), used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        state = vector<int>();
        used = vector<bool>(nums.size(), false);

        dfs(nums, 0);
        return ans;
    }
};

// soln 1: my soln

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> state;
    bool used[21] = {0};

    void dfs(vector<int> &nums, int pos) {
        // base case
        if (pos == nums.size()) {
            ans.push_back(state);
            return;
        }

        for (auto v : nums) {
            if (used[v + 10]) continue;
            // do choice
            state.push_back(v), used[v + 10] = true;
            // move on to next choice
            dfs(nums, pos + 1);
            // undo choice
            state.pop_back(), used[v + 10] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        dfs(nums, 0);
        return ans;
    }
};