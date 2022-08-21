// https://leetcode.com/problems/construct-smallest-number-from-di-string/

// solution 1: brute force

class Solution {
  public:
    string smallestNumber(string pattern) {
        string cur = "";
        for (int i = 1; i <= pattern.size() + 1; ++i) {
            cur += to_string(i);
        }

        while (true) {
            bool match = true;
            for (int i = 0; i < pattern.size(); ++i) {
                if (pattern[i] == 'I' && cur[i] > cur[i + 1]) {
                    match = false;
                    break;
                } else if (pattern[i] == 'D' && cur[i] < cur[i + 1]) {
                    match = false;
                    break;
                }
            }

            if (match) break;
            else next_permutation(cur.begin(), cur.end());
        }

        return cur;
    }
};

// soluton 2: conclusion

class Solution {
  public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";

        // init string
        for (int i = 1; i <= n + 1; i++) {
            ans += to_string(i);
        }

        // two pointer to find reverse range
        for (int i = 0; i < n; i++) {
            if (pattern[i] != 'D') continue;
            int j = i;
            while (j < n && pattern[j] == 'D') j++;
            // reverse substring
            reverse(ans.begin() + i, ans.begin() + j + 1);
            // jump to next location
            i = j;
        }

        return ans;
    }
};