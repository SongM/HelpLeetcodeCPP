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
    void helper(vector<int>& res, TreeNode* root, int level)
    {
        if (res.size()==level) res.push_back(root->val);
        if (root->right) helper(res, root->right, level+1);
        if (root->left) helper(res, root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return(res);
        helper(res,root,0);
        return(res);
        
    }
};