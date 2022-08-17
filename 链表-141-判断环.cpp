// https://leetcode.com/problems/linked-list-cycle/

// two pointer solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        auto s = head, f = head;
        while (f) {
            s = s->next, f = f->next;
            if (!f) return false;
            f = f->next;
            if (s == f) return true;
        }
        return false;
    }
};

// hash solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> hash;
        auto cur = head;
        while (cur && hash[cur] == 0) {
            hash[cur]++;
            cur = cur->next;
        }
        return cur == nullptr ? false : true;
    }
};