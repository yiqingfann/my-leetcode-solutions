class RandomizedSet {
  public:
    vector<int> nums;
    unordered_map<int, int> pos;

    RandomizedSet() {}

    bool insert(int val) {
        if (pos.count(val)) return false;
        nums.push_back(val);
        pos[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!pos.count(val)) return false;
        int x = val, px = pos[x], y = nums.back(), py = pos[y];
        swap(nums[px], nums[py]);
        swap(pos[x], pos[y]);
        nums.pop_back();
        pos.erase(x);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */