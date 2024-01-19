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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int count = 0;
        bool first = true;
        ListNode *result = head;
        ListNode *prev = nullptr;
        ListNode *rotation_end_prev = nullptr;
        while (true) {
            ListNode *start = head;
            while (head != NULL && count < k) {
                count++;
                ListNode *tmp = head;
                head = head->next;
                tmp->next = prev;
                prev = tmp;
            }
            // cout << "Count = " << count << " | prev->val = " << prev->val <<
            // "\n";
            if (head == NULL) {
                // cout << "HEAD == NULL\n";
                if (count < k) {
                    // cout << "COUNT = " << count << " < k\n";
                    while (prev != start) {
                        auto tmp = prev->next;
                        prev->next = head;
                        head = prev;
                        prev = tmp;
                    }
                    start->next = head;
                    return result;
                    // need to reverse everything we've done
                    // return here (!)
                } else {
                    cout << "COUNT = " << count << " == k\n";
                    // all good just return
                    if (first) {
                        first = false;
                        result = prev;
                    }
                    start->next = head;
                    if (rotation_end_prev != NULL) {
                        rotation_end_prev->next = prev;
                    }
                    rotation_end_prev = start;
                    // prev->next = head;
                    return result;
                }
            }
            if (first) {
                first = false;
                result = prev;
            }
            start->next = head;
            if (rotation_end_prev != NULL) {
                rotation_end_prev->next = prev;
            }
            rotation_end_prev = start;
            // cout << "HERE | start->val == " << start->val << " and
            // start->next = head, head->val = " << head->val << "\n";
            prev = nullptr;
            count = 0;
        }
    }
};