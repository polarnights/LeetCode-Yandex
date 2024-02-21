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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *result = head;
        ListNode *prev = NULL;
        ListNode *cur = head;
        int cur_diff = 1;
        while (head->next != NULL) {
            head = head->next;
            if (cur_diff < n) {
                cur_diff++;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        /*
        if (prev != NULL)
            cout << prev->val;
        if (cur != NULL)
            cout << cur->val;
        */
        if (prev == NULL) {
            return cur->next;
        }
        if (cur->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = cur->next;
        }
        return result;
    }
};