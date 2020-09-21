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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return(head);
        ListNode* h=head;
        ListNode* curr = h->next;
        while(curr!=NULL)
        {
            if (curr->val==h->val) h->next = curr->next;
            else h=h->next;
            curr = curr->next;
        }
        return(head);
    }
    
};