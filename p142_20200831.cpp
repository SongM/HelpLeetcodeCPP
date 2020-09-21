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
    ListNode *detectCycle(ListNode *head) {
        ListNode* h1 = head;
        ListNode* h2 = head;
        
        while(1)
        {
            // cout<<h1->val<<h2->val<<endl;
            if (h2==NULL or h2->next==NULL) return(NULL);
            h1 = h1->next;
            h2 = h2->next->next;
            if (h1==h2) break;
        }
        h1 = head;
        while(h1!=h2) 
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        return(h1);

    }
};