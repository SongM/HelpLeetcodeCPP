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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& m, int a, int b, int c, int d)
    {
        TreeNode* r=new TreeNode(preorder[a]);
        int i = m[preorder[a]];
        int left_l = i-c;
        int right_l = d-i;
        // cout<<a<<","<<b<<","<<c<<","<<d<<","<<endl;
        // cout<<preorder[a]<<','<<i<<endl;
        if (left_l==0) r->left = NULL;
        else r->left = helper(preorder,inorder,m,a+1,a+left_l,c,c+left_l-1);
        if (right_l==0) r->right = NULL;
        else r->right = helper(preorder,inorder,m,b-right_l+1,b,d-right_l+1,d);
        return(r);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size()==0) return(NULL);
        unordered_map<int,int> m;
        for (int i=0;i<inorder.size();i++) m[inorder[i]] = i;
        return(helper(preorder,inorder,m,0,preorder.size()-1,0,inorder.size()-1));
        
    }
};