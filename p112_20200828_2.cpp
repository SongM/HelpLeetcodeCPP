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
    bool helper(TreeNode* root, int sum)
    {
        sum -= root->val;
        if (root->left==NULL and root->right==NULL) return(sum==0);
        return((root->left!=NULL and helper(root->left, sum)) or (root->right!=NULL and helper(root->right, sum)));
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL) return(false);
        return(helper(root,sum));
    }
};