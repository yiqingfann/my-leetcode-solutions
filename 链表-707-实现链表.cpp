// https://leetcode.com/problems/design-linked-list/

struct Node {
    int val;
    Node *next;
    Node(int _val) : val(_val), next(nullptr) {}
};

class MyLinkedList {
    Node *dummy, *tail;
    int len;

  public:
    MyLinkedList() {
        tail = dummy = new Node(-1);
        len = 0;
    }

    int get(int index) {
        if (index < 0 || index > len - 1) return -1;

        auto cur = dummy;
        for (int i = 0; i < index + 1; ++i) cur = cur->next;

        return cur->val;
    }

    void addAtHead(int val) {
        auto t = new Node(val);
        t->next = dummy->next;
        dummy->next = t;
        // maintain tail and len
        if (!t->next) tail = t;
        len++;
    }

    void addAtTail(int val) {
        auto t = new Node(val);
        t->next = tail->next;
        tail->next = t;
        // maintain tail and len
        tail = t;
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > len) return;

        auto cur = dummy;
        for (int i = 0; i < index; ++i) cur = cur->next;
        auto t = new Node(val);
        t->next = cur->next;
        cur->next = t;

        if (index == len) tail = t;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > len - 1) return;

        auto cur = dummy;
        for (int i = 0; i < index; ++i) cur = cur->next;
        cur->next = cur->next->next;

        if (index == 0) tail = dummy;
        else if (index == len - 1) tail = cur;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */