// https://leetcode.com/problems/reverse-linked-list/

// recursive solution

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
    ListNode *reverseList(ListNode *head) {
        // base case
        if (!head || !head->next) return head;

        // compute solution based on smaller problem
        auto cur = head, nex = cur->next;
        auto tail = reverseList(nex);
        nex->next = cur, cur->next = nullptr;
        return tail;
    }
};

// iterative solution

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
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;

        ListNode *a = nullptr, *b = head;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        return a;
    }
};

// initial solution

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
    ListNode *reverseList(ListNode *head) {
        ListNode *cur, *hh = nullptr;
        for (cur = head; cur;) {
            auto t = cur->next;
            cur->next = hh, hh = cur;
            if (t) cur = t;
            else break;
        }
        return cur;
    }
};