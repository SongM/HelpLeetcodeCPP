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
    void helper(TreeNode* root, vector<vector<int>>& res, vector<int> &path, int& sum)
    {
        sum -= root->val;
        path.push_back(root->val);
        if (root->left==NULL and root->right==NULL) 
        {
            if(sum==0) res.push_back(path);
        }
        if (root->left!=NULL) helper(root->left, res, path, sum);
        if (root->right!=NULL) helper(root->right, res, path, sum);
        path.pop_back();
        sum += root->val;
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    
        vector<vector<int>> res;
        if (root==NULL) return(res);
        vector<int> path;
        helper(root,res,path,sum);
        return(res);
    }
};