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
    void helper(TreeNode* root, int &with, int& wout)
    {
        
        if (root==NULL) return;
        int l_with=0;
        int l_wout=0;
        int r_with=0;
        int r_wout=0;
        helper(root->left, l_with, l_wout);
        helper(root->right, r_with, r_wout);
        with = root->val + l_wout + r_wout;
        wout = max(l_with,l_wout) + max(r_with,r_wout);
        

    }
    int rob(TreeNode* root) {
        int with=0;
        int wout=0;
        helper(root,with,wout);
        return(max(with,wout));
    }
};