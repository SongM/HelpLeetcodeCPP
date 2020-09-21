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
    void helper(vector<vector<int>>& res, TreeNode* r, int level) {
        if (r==NULL) return;
        if (res.size()==level) res.push_back({});
        res[level].push_back(r->val);
        helper(res,r->left,level+1);
        helper(res,r->right,level+1);
        return;   
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (root==NULL) return(res);
        helper(res,root,0);
        return(res);

    }
};