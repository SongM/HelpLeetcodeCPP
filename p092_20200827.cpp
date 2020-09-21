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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* h = dummy;
        for (int i=1;i<m;i++) h=h->next;
        head = h;
        h = h->next;
        ListNode* tail=h;
        for (int i=0;i<n-m;i++)
        {
            h = tail->next;
            tail->next = h->next;
            h->next = head->next;
            head->next = h;
        }
        return(dummy->next);
        
    }
};