// watch out for boundary cases

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = head;
        for (int i=0;i<n;i++) h=h->next;
        if (h==NULL) return(head->next);
        ListNode* delay = head;
        
        while(h->next!=NULL)
        {
            h=h->next;
            delay=delay->next;
        }
        delay->next = delay->next->next;
        return(head);
    }
};