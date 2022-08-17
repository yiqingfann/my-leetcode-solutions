// https://leetcode.com/problems/swap-nodes-in-pairs/


// pointer solution

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
    ListNode *swapPairs(ListNode *head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        for (auto cur = dummy; cur->next && cur->next->next;) {
            auto a = cur->next, b = a->next, c = b->next;
            cur->next = b, b->next = a, a->next = c;
            cur = a;
        }

        return dummy->next;
    }
};

// stack solution

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
    ListNode *swapPairs(ListNode *head) {
        stack<ListNode *> stk;

        // push all nodes into stack
        auto cur = head;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }

        // init cur
        cur = nullptr;
        // special case for odd number of nodes
        if (stk.size() % 2 == 1) {
            cur = stk.top(), stk.pop();
        }

        // deal with all pairs
        while (stk.size() >= 2) {
            auto n1 = stk.top();
            stk.pop();
            auto n2 = stk.top();
            stk.pop();
            n1->next = n2, n2->next = cur, cur = n1;
        }

        return cur;
    }
};