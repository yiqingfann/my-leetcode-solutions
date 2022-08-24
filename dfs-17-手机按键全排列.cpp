// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// soln 2: pass state

class Solution {
  public:
    vector<string> ans;
    string letters[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string &digits, int pos, string state) {
        // base case
        if (pos == digits.size()) {
            ans.push_back(state);
            return;
        }

        for (auto c : letters[digits[pos] - '0']) {
            dfs(digits, pos + 1, state + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;

        dfs(digits, 0, "");
        return ans;
    }
};

// soln 1: my soln

class Solution {
  public:
    vector<string> ans;
    string tmp = "";
    string letters[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string &digits, int pos) {
        // base case
        if (pos == digits.size()) {
            if (tmp != "") ans.push_back(tmp);
            return;
        }

        for (auto c : letters[digits[pos] - '0']) {
            // do the choice
            tmp.push_back(c);
            // move on to next pos
            dfs(digits, pos + 1);
            // undo the choice
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        dfs(digits, 0);
        return ans;
    }
};