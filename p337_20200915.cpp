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
    vector<int> helper(TreeNode* root)
    {
        vector<int> res(2);
        if (root==NULL) return(res);
        vector<int> left_res = helper(root->left);
        vector<int> right_res = helper(root->right);
        res[0] = root->val + left_res[1] + right_res[1];
        res[1] = max(left_res[0],left_res[1]) + max(right_res[0],right_res[1]);
        return(res);
    }
    int rob(TreeNode* root) {
        vector<int> t = helper(root);
        return(max(t[0],t[1]));
    }
};