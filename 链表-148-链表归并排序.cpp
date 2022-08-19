// https://leetcode.com/problems/sort-list/

// note: complicated

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
    ListNode *sortList(ListNode *head) {
        // find total length
        int n = 0;
        for (auto t = head; t; t = t->next) n++;

        // repeat for each level
        for (int len = 1; len < n; len *= 2) {
            // save result of this level to dummy ~ tail
            auto dummy = new ListNode(-1), tail = dummy;
            // repeat for each start point
            auto s = head;
            while (s) {
                // store next start point
                auto ss = s;
                for (int r = 0; ss && r < len * 2; ++r) ss = ss->next;
                // move to first element of two parts
                auto i = s, j = s;
                for (int r = 0; j && r < len; ++r) j = j->next;
                // merge two parts
                int rem1 = len, rem2 = len;
                while (rem1 && rem2 && i && j) {
                    if (i->val < j->val)
                        tail = tail->next = i, rem1--, i = i->next;
                    else tail = tail->next = j, rem2--, j = j->next;
                }
                while (rem1 && i) tail = tail->next = i, rem1--, i = i->next;
                while (rem2 && j) tail = tail->next = j, rem2--, j = j->next;
                // forward start point
                s = ss;
            }
            // complete result of this level
            tail->next = nullptr;
            // move to next level
            head = dummy->next;
        }

        return head;
    }
};