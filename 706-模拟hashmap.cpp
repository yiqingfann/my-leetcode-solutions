// https://leetcode.com/problems/design-hashmap/

const int N = 19997;
typedef pair<int, int> pii;

class MyHashMap {
  public:
    vector<pii> h[N];

    MyHashMap() {}

    int find(vector<pii> &l, int target) {
        for (int i = 0; i < l.size(); ++i) {
            if (l[i].first == target) return i;
        }
        return -1;
    }

    void put(int key, int value) {
        int i = key % N;
        int j = find(h[i], key);
        if (j == -1) h[i].push_back({key, value});
        else h[i][j] = {key, value};
    }

    int get(int key) {
        int i = key % N;
        int j = find(h[i], key);
        if (j == -1) return -1;
        else return h[i][j].second;
    }

    void remove(int key) {
        int i = key % N;
        int j = find(h[i], key);
        if (j != -1) h[i].erase(h[i].begin() + j);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */