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
    int helper(unordered_map<TreeNode*, int>& m, TreeNode* r)
    {
        if (m.find(r)==m.end()) m[r] = helper(m,r->left)+helper(m,r->right)+1;
        return(m[r]);
    }
    int helper2(TreeNode* r, int k, unordered_map<TreeNode*, int>& m)
    {
        int left_size = helper(m, r->left);
        if (left_size==k-1) return(r->val);
        if (left_size>k-1) return(helper2(r->left,k,m));
        return(helper2(r->right,k-left_size-1,m));
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> m;
        m[NULL] = 0;
        return(helper2(root,k,m));
        
    }
};