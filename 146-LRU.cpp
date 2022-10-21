// https://leetcode.com/problems/lru-cache/

class LRUCache {
  public:
    /*
        O(1) get and put -> hash map
        O(1) maintain key order -> linked list

        example:
        (head) <-> (tail)
        put(1, 1): (head) <-> (1, 1) <-> (tail)
        put(2, 2): (head) <-> (2, 2) <-> (1, 1) <-> (tail)
        get(1): (head) <-> (1, 1) <-> (2, 2) <-> (tail)
        put(3, 3): (head) <-> (3, 3) <-> (1, 1) <-> (tail)

        use a map from key to node
        use node as key order, newest at the left
    */

    typedef struct Node {
        int key, val;
        Node *prev, *next;
        Node(int _key, int _val)
            : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    } Node;

    unordered_map<int, Node *> hash;
    Node *head, *tail;
    int cap;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    void remove(Node *cur) {
        auto l = cur->prev, r = cur->next;
        l->next = r;
        r->prev = l;
    }

    void insertHead(Node *cur) {
        auto l = head, r = head->next;
        l->next = cur;
        cur->prev = l, cur->next = r;
        r->prev = cur;
    }

    int get(int key) {
        // if key doesn't exist, return -1
        if (!hash.count(key)) return -1;

        // if key exist
        // get the node
        // remove the node
        // insert the node to the head
        // return the value
        auto cur = hash[key];
        remove(cur);
        insertHead(cur);
        return cur->val;
    }

    void put(int key, int value) {
        // if key exist
        // get the node
        // update the value
        // remove the node
        // insert the node to the head
        if (hash.count(key)) {
            auto cur = hash[key];
            cur->val = value;
            remove(cur);
            insertHead(cur);
        }

        // if key doesn't exist
        // if reach cap, remove the last node
        // create a new node
        // insert the node to the head
        // save to hash
        else {
            if (hash.size() == cap) {
                auto t = tail->prev;
                remove(t);
                hash.erase(t->key);
            }
            auto cur = new Node(key, value);
            insertHead(cur);
            hash[key] = cur;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// soln: TLE

typedef struct Node {
    int key;
    Node *prev, *next;
} Node;

class LRUCache {
  public:
    /*
        implement the cache as linked list and hash map
        linkedlist to maintain the order of keys so we know what to delete
        hashmap to maintain the value

        dummy = head = tail <-> nullptr
        put(1, 1): dummy <-> 1 (head, tail) <-> nullptr
        put(2, 2): dummy <-> 1 (head) <-> 2 (tail) <-> nullptr
        get(1): dummy <-> 2 (head) <-> 1 (tail) <-> nullptr
        put(3, 3): dummy <-> 1 (head) <-> 3 (tail) <-> nullptr

        pre <-> cur <-> nullptr
        pre <-> cur <-> next

    */
    unordered_map<int, int> kv;
    unordered_map<int, Node *> kn;
    Node *dummy, *head, *tail;
    int cap;

    LRUCache(int capacity) {
        dummy = new Node();
        head = tail = dummy;
        cap = capacity;
    }

    void moveToEnd(int key) {
        auto cur = kn[key], pre = cur->prev, nex = cur->next;
        if (nex) {
            pre->next = nex;
            nex->prev = pre;
            cur->prev = tail, cur->next = nullptr;
            head = dummy->next;
            tail->next = cur, tail = cur;
        }
    }

    int get(int key) {
        // check if key exist
        // if not, return -1
        if (!kv.count(key)) return -1;

        // if exist, put the node to the end
        moveToEnd(key);

        // return the value
        return kv[key];
    }

    void put(int key, int value) {
        // check if key exist
        // if exist
        // move the node to the end
        // update the value
        if (kv.count(key)) {
            moveToEnd(key);
            kv[key] = value;
        } else {
            if (kv.size() == cap) {
                // special case size == 1
                int t = head->key;
                if (kv.size() == 1) {
                    dummy->next = nullptr;
                    head = tail = dummy;
                }
                // general case size > 1
                else if (kv.size() > 1) {
                    auto pre = head->prev, nex = head->next;
                    pre->next = nex, nex->prev = pre;
                    head = dummy->next;
                }
                kv.erase(t);
                kn.erase(t);
            }
            auto cur = new Node();
            cur->key = key;
            cur->prev = tail, cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            if (head == dummy) head = cur;

            kv[key] = value;
            kn[key] = cur;
        }

        // if not exist
        // if cache is full, delete least recently used key
        // add a new node to the end
        // save the value
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// soln: error

typedef struct Node {
    int key, val;
    Node *prev, *next;
} Node;

class LRUCache {
  public:
    /*
        1, 2, 1, 3, 2, 4, 1, 3, 4
        maintain a map from key -> Node *
        maintain size, head, and tail of a double linked list
        whenever get or put, put the key to the end, and execute operation
        if put and exceed cap, delete head
        x -> y -> z
        x -> y
        dummy <-> head <-> nex <-> ... <-> tail -> nullptr
        dummy <-> head = tail -> nullptr

        dummy = head = tail -> nullptr

    */

    unordered_map<int, Node *> hash;
    int size;
    Node *dummy, *head, *tail;

    int cap;

    LRUCache(int capacity) {
        dummy = new Node();
        head = tail = dummy;
        size = 0;
        cap = capacity;
    }

    int get(int key) {
        printf("get %d\n", key);
        if (!hash.count(key)) return -1;

        auto y = hash[key], x = y->prev, z = y->next;
        if (!z) return tail->val;

        x->next = z, z->prev = x;
        y->prev = tail, y->next = nullptr;
        tail->next = y, tail = y;
        return tail->val;
    }

    void put(int key, int value) {
        printf("put %d %d\n", key, value);
        // if full and key is new, remove least recently used key
        if (size == cap & !hash.count(key)) {
            if (size == 1) {
                hash.erase(head->key);
                size--;
                dummy->next = nullptr;
                head = tail = dummy;
            } else {
                hash.erase(head->key);
                size--;
                auto nex = head->next;
                dummy->next = nex, nex->prev = dummy;
            }
        }

        // insert
        auto cur = new Node();
        cur->key = key, cur->val = value;
        cur->prev = tail, cur->next = nullptr;
        if (size == 0) {
            head = tail = cur;
            dummy->next = head;
        } else {
            tail->next = cur;
            tail = cur;
        }
        hash[key] = cur;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */