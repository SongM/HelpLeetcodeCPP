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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL) return(false);
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0)
        {
            TreeNode* r=v.back();
            v.pop_back();
            if (r->left==NULL and r->right==NULL)
            {
                if (r->val==sum) return(true);
                continue;
            }
            if (r->left!=NULL) 
            {
                r->left->val += r->val;
                v.push_back(r->left);
            }
            if (r->right!=NULL) 
            {
                r->right->val += r->val;
                v.push_back(r->right);
            }
        }
        return(false);
    }
};