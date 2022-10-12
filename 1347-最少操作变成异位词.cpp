// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
  public:
    int minSteps(string s, string t) {
        /*
            s = "babc"
            a: 1
            b: 2
            c: 1

            t = "abab"
            a: 2
            b: 2
            # redundent = # lack
            just get frequency map of s and t
            count # redundent
        */

        // preprocess to get char freq
        unordered_map<char, int> f1, f2;
        for (auto c : s) {
            f1[c]++;
        }
        for (auto c : t) {
            f2[c]++;
        }

        // count number of redundent chars
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (f2[c] > f1[c]) {
                ans += f2[c] - f1[c];
            }
        }
        return ans;
    }
};