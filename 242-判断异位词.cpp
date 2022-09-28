// https://leetcode.com/problems/valid-anagram/

class Solution {
  public:
    bool isAnagram(string s, string t) {
        // // anagram should have exact the same char freq
        // vector<int> f1(26, 0), f2(26, 0);
        // for (auto c : s) f1[c - 'a']++;
        // for (auto c : t) f2[c - 'a']++;
        // return f1 == f2;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};