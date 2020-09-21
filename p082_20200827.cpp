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
        if (head==NULL or head->next==NULL) return(head);
        ListNode* dummy=new ListNode;
        dummy->val = head->val-1;
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next!=NULL)
        {
            // cout<<curr->val;
            ListNode* h=curr->next;
            while(h->next!=NULL and h->next->val==curr->next->val) h=h->next;
            if (h!=curr->next) curr->next = h->next;
            else curr = curr->next;
        }
        return(dummy->next);
    }
};