// use heap to achieve every insert by complexity O(logK)
// in total 
// if use divide and conquer, each time only combine 2 list 
// 8 lists became 4 lists became 2 lists then the final list
// logK times combining, each combine is O(N) => NlogK time complexity

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<pair<int, ListNode*>> v;
        pair<int,ListNode*> p;
        for (auto l:lists)
        {
            if (l!=NULL)
            {
                p.first = -l->val;
                p.second = l;
                v.push_back(p);
            }
        }
        if (v.size()==0) return(NULL);
        
        ListNode* dummy = new ListNode;
        ListNode* h = dummy;
        make_heap(v.begin(),v.end());       
        while(v.size()>1)
        {
            pop_heap(v.begin(),v.end());
            p = v.back();
            v.pop_back();
            h->next = p.second;
            h = h->next;
            if (p.second->next!=NULL)
            {
                p.first = -p.second->next->val;
                p.second = p.second->next;
                v.push_back(p); 
                push_heap(v.begin(), v.end()); 
            }
        }
        h->next = v[0].second;
        return(dummy->next);
    }
};