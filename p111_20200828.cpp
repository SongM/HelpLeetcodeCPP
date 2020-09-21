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
    void helper(TreeNode* r, int level, int& res)
    {
        if (res>=0 and level>=res) return;
        if (r->left==NULL and r->right==NULL) {res=level;return;}
        if (r->left!=NULL) helper(r->left, level+1, res);
        if (r->right!=NULL) helper(r->right, level+1, res);
        
    }
    int minDepth(TreeNode* root) {
        if (root==NULL) return(0);
        int res = -1;
        helper(root,1,res);
        return(res);
    }
};