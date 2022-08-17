// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    struct Compare {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // inseart list heads into min heap
        priority_queue<ListNode *, vector<ListNode *>, Compare> mh;
        for (auto l : lists) {
            if (!l) continue;
            mh.push(l);
        }

        // add to result one at a time
        auto dummy = new ListNode(-1), tail = dummy;
        while (mh.size()) {
            auto t = mh.top();
            mh.pop();
            tail = tail->next = t;
            if (t->next) mh.push(t->next);
        }

        return dummy->next;
    }
};