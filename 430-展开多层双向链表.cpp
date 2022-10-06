// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
  public:
    Node *dfs(Node *u) {
        // base case

        // build result from sub-results
        auto cur = u;
        Node *ret = nullptr;
        while (cur) {
            ret = cur;
            auto nex = cur->next;
            auto chi = cur->child;
            if (chi) {
                auto tail = dfs(chi);
                ret = tail;
                cur->next = chi, cur->child = nullptr;
                chi->prev = cur;
                tail->next = nex;
                if (nex) nex->prev = tail;
            }
            cur = nex;
        }
        return ret;
    }

    Node *flatten(Node *head) {
        // want a function dfs(u), that flattens the list starting at u and
        // return the tail so for current function, we need to let cur start
        // from u, if cur has no child, advance cur if cur has a child, flatten
        // cur with tail = dfs(cur->child) reconnect: cur -> cur child -> ... ->
        // tail -> cur next set cur->child to null advance cur to cur next
        dfs(head);
        return head;
    }
};