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
    int helper(TreeNode* r)
    {
        if (r==NULL) return(0);
        
        int le=helper(r->left);
        if (le==-1) return(-1);
        int ri=helper(r->right);
        if (ri==-1) return(-1);
        if (le>ri+1 or ri>le+1) return(-1);        
        return((le>ri?le:ri)+1);
    }
    bool isBalanced(TreeNode* root) {
        
        return(helper(root)>=0);
        
    }
};