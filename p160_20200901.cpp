/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* h=headA;
        while(h!=NULL)
        {
            len1++;
            h = h->next;
        }
        h=headB;
        while(h!=NULL)
        {
            len2++;
            h = h->next;
        }
        for (int l=len1;l<len2;l++) headB = headB->next;
        for (int l=len2;l<len1;l++) headA = headA->next;
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return(headA);
        
    }
};