void printListNode(ListNode* head) 
{
    while(head!=NULL)
    {cout<<head->val<<",";head=head->next;}
    cout<<endl;
    return;
}


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
    void reorderList(ListNode* head) {
        if (head==NULL or head->next==NULL) return;
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        while(h2!=NULL and h2->next!=NULL)
        {
            h1 = h1->next;
            h2 = h2->next->next;
        }
        h2 = h1->next;
        while(h2->next!=NULL)
        {
            ListNode* hh = h1->next;
            h1->next = h2->next;
            h2->next = h1->next->next;
            h1->next->next = hh;
        }
        
        h2 = h1->next;
        h1->next = NULL;
        h1 = head;
        while(h2!=NULL)
        {
            ListNode* hh = h1->next;
            h1->next = h2;
            h2 = h2->next;
            h1->next->next = hh;
            h1 = h1->next->next;
        }
        
        
        
        return;
    }
};