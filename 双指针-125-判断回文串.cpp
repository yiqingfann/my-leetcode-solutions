// https://leetcode.com/problems/valid-palindrome/

// soln 1

class Solution {
  public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }

        return true;
    }
};

// soln 2

class Solution {
  public:
    bool isPalindrome(string s) {
        // remove non alphanumeric
        auto new_end =
            remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); });
        s.erase(new_end, s.end());
        // turn into lower
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // check problem
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }

        return true;
    }
};