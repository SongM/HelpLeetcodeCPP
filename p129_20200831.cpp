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
    void helper(int& res, TreeNode* r)
    {
        if (r->left==NULL and r->right==NULL) {res+=r->val;return;}
        if (r->left!=NULL) {r->left->val = r->left->val + r->val*10;helper(res,r->left);}
        if (r->right!=NULL) {r->right->val = r->right->val + r->val*10;helper(res,r->right);}
        return;
        
    }
    int sumNumbers(TreeNode* root) {
        if (root==NULL) return(0);
        int res = 0;
        helper(res,root);
        return(res);
    }
};