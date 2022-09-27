// https://leetcode.com/problems/design-hashset/submissions/

const int N = 19997;

class MyHashSet {
  public:
    vector<int> h[N];

    MyHashSet() {}

    int find(vector<int> &l, int target) {
        for (int i = 0; i < l.size(); ++i) {
            if (l[i] == target) return i;
        }
        return -1;
    }

    void add(int key) {
        int i = key % N;
        int j = find(h[i], key);
        if (j == -1) h[i].push_back(key);
    }

    void remove(int key) {
        int i = key % N;
        int j = find(h[i], key);
        if (j != -1) h[i].erase(h[i].begin() + j);
    }

    bool contains(int key) {
        int i = key % N;
        int j = find(h[i], key);
        return (j != -1);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */