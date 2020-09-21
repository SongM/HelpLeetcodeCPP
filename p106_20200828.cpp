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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& m, int a, int b, int c, int d)
    {
        
        TreeNode* r=new TreeNode(postorder[d]);
        int i = m[postorder[d]];
        if (i-a==0) r->left = NULL;
        else r->left = helper(inorder,postorder,m,a,i-1,c,c+i-a-1);
        if (b-i==0) r->right = NULL;
        else r->right = helper(inorder,postorder,m,i+1,b,d-b+i,d-1);
        return(r);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for (int i=0;i<inorder.size();i++) m[inorder[i]] = i;
        if (inorder.size()==0) return(NULL);
        return(helper(inorder,postorder,m,0,inorder.size()-1,0,postorder.size()-1));
    }
};