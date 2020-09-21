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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode();
        ListNode* l2 = new ListNode();
        ListNode* ll1=l1;
        ListNode* ll2=l2;
        while(head!=NULL)
        {
            if (head->val<x) {ll1->next = head; ll1 = ll1->next;}
            else {ll2->next = head; ll2 = ll2->next;}
            head = head->next;
            ll1->next = NULL;
            ll2->next = NULL;
        }
        ll1->next = l2->next;
        return(l1->next);
    }
};