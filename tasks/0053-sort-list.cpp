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
        if (head == NULL) {
            return head;
        }
        vector<ListNode *> elems;
        while (head != NULL) {
            elems.push_back(head);
            head = head->next;
        }
        auto cmp = [](ListNode *a, ListNode *b) { return a->val < b->val; };
        sort(elems.begin(), elems.end(), cmp);
        for (int i = 0; i < elems.size() - 1; i++) {
            elems[i]->next = elems[i + 1];
        }
        elems.back()->next = nullptr;
        return elems[0];
    }
};