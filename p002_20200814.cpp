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

// use extra space could save the last traverse
// use extra comparison could also save the last traverse
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        int carry = 0;
        while(ll1)
        {
            int sum = carry+ll1->val;
            carry = 0;
            if (ll2) sum+=ll2->val;
            if (sum>=10)
            {
                sum = sum-10;
                carry = 1;
            }
            ll1->val = sum;
            ll1 = ll1->next;
            if (ll2) 
            {
                ll2->val = sum;
                ll2 = ll2->next;
                if (ll1==NULL)
                {
                    ll1 = ll2;
                    ll2 = NULL;
                    l1 = l2;
                }
            }
        }
        if (carry==1)
        {
            ll1 = l1;
            while(ll1->next) ll1 = ll1->next;
            ll1->next = new ListNode(1);
        }
        return(l1);
    }
};