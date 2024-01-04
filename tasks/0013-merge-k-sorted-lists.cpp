// Idea taken from leetcode explanation
// TODO: Find out how was std::priority_queue implemented?


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}
 

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

// TODO: Recall how std::greater<T> works
// TODO: Solve this using "Divide&Conquer"
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> queue;
        for (auto& elem: lists) {
            if (elem != NULL) {
                queue.push({elem->val, elem});
            }
        }
        while (!queue.empty()) {
            auto current = queue.top();
            temp->next = current.second;
            temp = temp->next;
            queue.pop();
            if (current.second->next != NULL) {
                queue.push({current.second->next->val, current.second->next});
            }
        }
        return result->next;
    }
};
