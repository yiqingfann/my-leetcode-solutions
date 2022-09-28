// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
  public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> pos;

    RandomizedCollection() {}

    bool insert(int val) {
        bool ret = pos.count(val) ? false : true;

        nums.push_back(val);
        pos[val].insert(nums.size() - 1);

        return ret;
    }

    bool remove(int val) {
        bool ret = pos.count(val) ? true : false;
        if (!ret) return ret;

        int x = val, px = *pos[x].begin();
        int y = nums.back(), py = nums.size() - 1;

        swap(nums[px], nums[py]);
        pos[x].erase(px), pos[x].insert(py);
        pos[y].erase(py), pos[y].insert(px);

        nums.pop_back();
        pos[x].erase(py);
        if (!pos[x].size()) pos.erase(x);

        return ret;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */