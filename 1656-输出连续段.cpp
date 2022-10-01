// https://leetcode.com/problems/design-an-ordered-stream/

class OrderedStream {
  public:
    vector<string> a;
    int pos;

    OrderedStream(int n) {
        // a vector of length n
        // a pointer to the start of next chunck to be returned
        // if insert != ptr, insert
        // if insert == ptr, insert and move ptr to output chunck
        a.resize(n + 1, "#");
        pos = 1;
    }

    vector<string> insert(int idKey, string value) {
        a[idKey] = value;
        vector<string> ans;
        if (idKey == pos) {
            while (pos < a.size() && a[pos] != "#") {
                ans.push_back(a[pos]);
                pos++;
            }
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */