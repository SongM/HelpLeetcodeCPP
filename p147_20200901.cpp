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
    ListNode* insertionSortList(ListNode* head) {
        if (head==NULL) return(head);
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* tail = head;
        while(tail->next!=NULL)
        {
            ListNode* curr = tail->next;
            head = dummy;
            while(head->next->val<curr->val)
            {
                if (curr->val > head->next->val) head=head->next;
            }
            if (head==tail) tail = tail->next;
            else
            {
                tail->next = curr->next;
                curr->next = head->next;
                head->next = curr;
            }
        }
        return(dummy->next);
    }
};