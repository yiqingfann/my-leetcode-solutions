// https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
  public:
    vector<string> hist;
    int cur, last;

    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        cur = 0, last = 0;
    }

    void visit(string url) {
        // while (last > cur) hist.pop_back(), --last;
        // hist.push_back(url), ++cur, ++last;
        ++cur, last = cur;
        if (cur < hist.size()) hist[cur] = url;
        else hist.push_back(url);
    }

    string back(int steps) {
        // while (cur > 0 && steps--) --cur;
        cur = max(cur - steps, 0);
        return hist[cur];
    }

    string forward(int steps) {
        // while (cur < last && steps--) ++cur;
        cur = min(cur + steps, last);
        return hist[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */