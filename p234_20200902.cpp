/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void printListNode(ListNode* head) 
{
    while(head!=NULL)
    {cout<<head->val<<",";head=head->next;}
    cout<<endl;
    return;
}

ListNode* reverseListNode(ListNode* head)
{
    if (head==NULL or head->next==NULL) return(head);
    ListNode* h1 = reverseListNode(head->next);
    ListNode* h2 = head->next;
    head->next = NULL;
    h2->next = head;
    return(h1);        
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL or head->next==NULL) return(true);
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        while(h2!=NULL and h2->next!=NULL)
        {
            h2 = h2->next->next;
            h1 = h1->next;
        }
        cout<<h1->val;
        h1->next = reverseListNode(h1->next);
        // printListNode(head);
        h1 = h1->next;
        while(h1!=NULL)
        {
            if (h1->val!=head->val) return(false);
            h1 = h1->next;
            head = head->next;
        }
        
        return(true);
    }
};