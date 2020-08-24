// straightforward extention of p024
// notice besides the head and tail, a curr pointer (h in the following code) is used to indicate the current working node.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL or k<=1) return(head);
        ListNode* dummy = new ListNode; 
        dummy->next = head;
        ListNode* tail = dummy;
        while(1)
        {
            ListNode* h=head;
            for (int i=0;i<k;i++)
            {
                if (h==NULL) return(dummy->next);;
                h=h->next;
            }
            h = head;
            for (int i=1;i<k;i++)
            {
                tail->next = h->next;
                h->next = tail->next->next;
                tail->next->next = head;
                head = tail->next;
            }
            tail = h;
            head = tail->next;
            
        }
        return(dummy->next);


    }
};