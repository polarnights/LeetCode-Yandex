#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        // Handling empty list just in case
        if (head == NULL) {
            return head;
        }
        ListNode *current = head;
        ListNode *prev = nullptr;
        while (current != NULL) {
            auto tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }
        return prev;
        // TODO: why does
        // return prev; WORK, WHILE return current->next; does not?
        // Is it actually UB when current->next == tmp is nullptr and we assign
        // nullptr->next = ...?
    }
};