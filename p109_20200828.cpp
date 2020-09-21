// can also convert the listnode to a vector, then acheives O(N) time complexity

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* head, ListNode* tail)
    {
        if (head==tail) return(NULL);
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != tail and fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* r = new TreeNode(slow->val);
        r->left = helper(head,slow);
        r->right = helper(slow->next,tail);
        return(r);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return(helper(head,NULL));
        
    }
};