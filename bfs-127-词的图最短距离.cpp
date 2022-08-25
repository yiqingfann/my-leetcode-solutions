// https://leetcode.com/problems/word-ladder/

// soln: O(26nl^2)

typedef pair<string, int> psi;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_map<string, bool> exist, used;
        for (auto w : wordList) exist[w] = true;

        queue<psi> q;
        q.push({beginWord, 1});

        while (q.size()) {
            auto [t, d] = q.front();
            q.pop();
            for (int i = 0; i < t.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    auto tt = t;
                    tt[i] = c;
                    if (!exist[tt] || used[tt]) continue;
                    q.push({tt, d + 1});
                    used[tt] = true;
                    if (tt == endWord) return d + 1;
                }
            }
        }

        return 0;
    }
};

// my init soln (TLE): O(ln^2)

typedef pair<string, int> psi;

class Solution {
  public:
    int diff(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        // check if endWord exist
        bool exist = false;
        for (auto w : wordList) {
            if (w == endWord) {
                exist = true;
                break;
            }
        }
        if (!exist) return 0;

        // enqueue endWord
        unordered_map<string, bool> used;

        queue<psi> q;
        q.push({endWord, 1});
        used[endWord] = true;

        while (q.size()) {
            auto t = q.front();
            q.pop();
            // check if t and begin word differ by 1
            int dist = diff(t.first, beginWord);
            if (dist == 1) return t.second + 1;
            if (dist == 0) return t.second;
            // enqueue all word that is unused and differ t by one
            for (auto w : wordList) {
                if (used[w] || diff(w, t.first) != 1) continue;
                q.push({w, t.second + 1});
                used[w] = true;
            }
        }

        return 0;
    }
};