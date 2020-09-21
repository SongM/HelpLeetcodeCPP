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
        vector<ListNode*> v;
        ListNode* h=head;
        while(h!=NULL) 
        {
            v.push_back(h);
            h = h->next;
            v.back()->next=NULL;
        }
        int i=0;
        int j=v.size()-1;
        v[0]->next = v[j];
        h = v[j];
        i++;
        j--;
        while(1)
        {
            if (i>j) break;
            h->next = v[i];
            h = h->next;
            i++;
            if (i>j) break;
            h->next = v[j];
            h = h->next;
            j--;
        }
        return;
    }
};