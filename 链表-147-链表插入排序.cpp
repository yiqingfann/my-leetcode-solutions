// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode *insertionSortList(ListNode *head) {
        auto dummy = new ListNode(-1);

        for (auto cur = head; cur;) {
            // store nex
            auto nex = cur->next;
            // find node t, where cur should be placed after t
            auto t = dummy;
            while (t->next && t->next->val <= cur->val) t = t->next;
            // place cur
            cur->next = t->next, t->next = cur;
            // move to next element
            cur = nex;
        }

        return dummy->next;
    }
};