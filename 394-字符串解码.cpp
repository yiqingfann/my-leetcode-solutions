// https://leetcode.com/problems/decode-string/

class Solution {
  public:
    string dfs(string u) {
        // assume a function dfs(u) that decodes string u
        // for example u = "abc345[a2[c]]ef2[a]"
        // find the outermost u = "...k[v]..." and get t = dfs(v), add k times
        // of t to res repeat until u ends

        // build result from sub-results
        string res = "";
        int n = u.size();
        for (int i = 0; i < n; ++i) {
            // put all non-numbers to res
            int j = i;
            while (j < n && !('0' <= u[j] && u[j] <= '9')) ++j;
            res += u.substr(i, j - i);
            if (j == n) break;
            // get the number k
            i = j;
            while (j < n && u[j] != '[') ++j;
            // cout << u << " " << i << " " << j << " " << u.substr(i, j - i) <<
            // endl;
            int k = stoi(u.substr(i, j - i));
            // find matching bracket
            i = j + 1;
            int lcnt = 1, rcnt = 0;
            while (j < n && lcnt != rcnt) {
                ++j;
                if (u[j] == '[') ++lcnt;
                else if (u[j] == ']') ++rcnt;
            }
            string v = u.substr(i, j - i);
            string t = dfs(v);
            // cout << k << " " << v << " " << t << endl;
            while (k--) res += t;
            i = j;
        }


        return res;
    }

    string decodeString(string s) {
        // ans is dfs(s)
        return dfs(s);
    }
};