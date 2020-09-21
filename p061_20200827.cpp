class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL) return(head);
        
        int l=1;
        ListNode* tail = head;
        while(tail->next!=NULL) {l++;tail=tail->next;}
        k = k%l;
        if (k==0) return(head);
        ListNode* h = head;
        while(k<l-1)
        {
            h=h->next;
            k++;
        }
        ListNode* hh = h->next;
        h->next = NULL;
        tail->next = head;
        return(hh);
    }
};