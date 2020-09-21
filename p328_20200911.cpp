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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode;
        ListNode* odd = new ListNode;
        ListNode* even_h = even;
        ListNode* odd_h = odd;
        while(head and head->next)
        {
            odd_h->next = head;
            even_h->next = head->next;
            head = head->next->next;
            odd_h = odd_h->next;
            even_h = even_h->next;
            odd_h->next = NULL;
            even_h->next = NULL;
        }
        if (head!=NULL) {odd_h->next = head;odd_h=odd_h->next;}
        odd_h->next = even->next;
        return(odd->next);

        
    }
};