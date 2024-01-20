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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return head;
        }

        int size = 1;
        auto tmp = head;
        while (tmp->next != NULL) {
            size++;
            tmp = tmp->next;
        }

        k = (k % size);
        if (k == 0) {
            return head;
        }

        // k >= 1; size = size(...)
        auto saved_head = head;
        while (size != k + 1) {
            // cout << "Size = " << size << " , cur_value = " << head->val <<
            // "\n";
            head = head->next;
            size--;
        }

        ListNode *result = head->next;
        tmp->next = saved_head;
        head->next = nullptr;
        return result;
    }
};