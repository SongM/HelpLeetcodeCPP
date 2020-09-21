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
    void helper(vector<string>& res, vector<int>& path, TreeNode* r)
    {
        if (r->left == NULL and r->right == NULL)
        {
            string t_res;
            for (auto p:path) t_res+=to_string(p)+"->";
            t_res+=to_string(r->val);
            res.push_back(t_res);
            return;
        }
        path.push_back(r->val);
        if (r->left!=NULL) helper(res,path,r->left);
        if (r->right!=NULL) helper(res,path,r->right);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root==NULL) return(res);
        vector<int> path;
        helper(res,path,root);
        return(res);
        
    }
};