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
    ListNode* sortList(ListNode* head) {
        
        if (head==NULL or head->next==NULL) return(head);
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        head = sortList(head);
        fast = sortList(fast);
        ListNode* res;
        if (head->val<fast->val)
        {
            res = head;
            head = head->next;
        }
        else
        {
            res = fast;
            fast = fast->next;
        }            
        slow = res;
        while(head!=NULL or fast!=NULL)
        {
            if (head==NULL or (fast!=NULL and fast->val<head->val))
            {
                slow->next = fast;
                fast = fast->next;
            }
            else
            {
                slow->next = head;
                head = head->next;
            }
            slow = slow->next;
        }
        return(res);
    }
};