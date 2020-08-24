// for listnode problem, clearly define the head and tail that you are working on
// make the draft first on how listnode pointing changes.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode; 
        dummy->next = head;
        ListNode* tail = dummy;
        while(head!=NULL and head->next!=NULL)
        {
            tail->next = head->next;
            head->next = tail->next->next;
            tail->next->next = head;
            tail = head;
            head = head->next;
        }
        return(dummy->next);
    }
};