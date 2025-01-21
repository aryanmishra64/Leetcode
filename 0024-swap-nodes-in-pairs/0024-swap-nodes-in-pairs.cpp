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
    ListNode* swapPairs(ListNode* head) {
        // empty || single
        if (!head || !head->next) return head;

        // ek case mai solve krunga baaki rec sambhalega
        ListNode* curr = head;
        ListNode* forward = curr->next;
        // rearrange
        curr->next = forward->next;
        forward->next = curr;
        curr->next = swapPairs(curr->next);

        return forward;
    }
};