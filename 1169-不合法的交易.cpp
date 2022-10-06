// https://leetcode.com/problems/invalid-transactions/

// soln 2: O(nlogn)

struct Trans {
    string orig;
    string name, city;
    int time, amount;
    bool isValid;

    Trans(string _orig) {
        orig = _orig;
        stringstream ss(orig);
        string tmp;
        getline(ss, tmp, ','), name = tmp;
        getline(ss, tmp, ','), time = stoi(tmp);
        getline(ss, tmp, ','), amount = stoi(tmp);
        getline(ss, tmp, ','), city = tmp;
        isValid = (amount <= 1000);
    }

    bool operator<(const Trans &t) {
        return time < t.time;
    }
};

class Solution {
  public:
    vector<string> invalidTransactions(vector<string> &transactions) {
        // for determine if a transaction is invalid, we need
        // all transactions with the same name
        // check if during [t - 60, t + 60] another city exists

        // preprocess string into name, time, amount, city
        // classify based on name
        unordered_map<string, vector<Trans>> hash;
        for (auto &t : transactions) {
            auto trans = Trans(t);
            hash[trans.name].push_back(trans);
        }

        // for each name, sort based on time
        vector<string> ans;
        for (auto &[k, v] : hash) {
            // use two pointers scan once to check [t - 60, t]
            sort(v.begin(), v.end());
            unordered_map<string, int> cnt;
            for (int i = 0, j = 0; i < v.size(); ++i) {
                cnt[v[i].city]++;
                while (v[i].time - v[j].time > 60) {
                    cnt[v[j].city]--;
                    if (cnt[v[j].city] == 0) cnt.erase(v[j].city);
                    ++j;
                }
                if (cnt.size() > 1) v[i].isValid = false;
            }

            // use two pointers scan once to check [t, t + 60]
            reverse(v.begin(), v.end());
            cnt.clear();
            for (int i = 0, j = 0; i < v.size(); ++i) {
                cnt[v[i].city]++;
                while (v[j].time - v[i].time > 60) {
                    cnt[v[j].city]--;
                    if (cnt[v[j].city] == 0) cnt.erase(v[j].city);
                    ++j;
                }
                if (cnt.size() > 1) v[i].isValid = false;
            }

            for (int i = 0; i < v.size(); ++i) {
                if (v[i].isValid) continue;
                ans.push_back(v[i].orig);
            }
        }

        return ans;
    }
};

// soln 1: O(n^2)

class Solution {
  public:
    vector<string> invalidTransactions(vector<string> &transactions) {
        int n = transactions.size();
        vector<string> ans;

        // preprocess to parse string
        vector<string> name(n, ""), city(n, "");
        vector<int> time(n, 0), amount(n, 0);
        for (int i = 0; i < n; ++i) {
            stringstream ss(transactions[i]);
            string na, ti, am, ci;
            getline(ss, na, ','), name[i] = na;
            getline(ss, ti, ','), time[i] = stoi(ti);
            getline(ss, am, ','), amount[i] = stoi(am);
            getline(ss, ci, ','), city[i] = ci;
        }

        // brute force compare
        vector<bool> isInvalid(n, false);
        for (int i = 0; i < n; ++i) {
            if (isInvalid[i]) continue;
            if (amount[i] > 1000) {
                ans.push_back(transactions[i]);
                isInvalid[i] = true;
                continue;
            } else {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    if (name[i] == name[j] && abs(time[i] - time[j]) <= 60 &&
                        city[i] != city[j]) {
                        ans.push_back(transactions[i]);
                        isInvalid[i] = true;
                        if (!isInvalid[j]) {
                            ans.push_back(transactions[j]);
                            isInvalid[j] = true;
                        }
                        break;
                    }
                }
            }
        }

        return ans;
    }
};