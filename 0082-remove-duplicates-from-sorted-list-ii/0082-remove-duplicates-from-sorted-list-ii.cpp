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
     ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }
        
        int x=head->val;
        int y=head->next->val;
        
        if(x!=y)
        {
            head->next=deleteDuplicates(head->next);
        }
        else
        {
            while(head && x==head->val)
            {
                head=head->next;
            }
           return deleteDuplicates(head);
        }
     
        return head;
    }
};