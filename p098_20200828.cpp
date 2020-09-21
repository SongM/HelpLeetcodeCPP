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
    vector<int> helper(TreeNode* r)
    {
        vector<int> v={r->val,r->val,1};
        
        if (r->left!=NULL) 
        {
            vector<int> v_l = helper(r->left);
            if (v_l[2]==0) return(v_l);
            if(r->val<=v_l[1]) {v[2]=0;return(v);}
            if(v[0]>v_l[0]) v[0]=v_l[0];
        }
        if (r->right!=NULL) 
        {
            vector<int> v_r = helper(r->right);
            if (v_r[2]==0) return(v_r);
            if(r->val>=v_r[0]) {v[2]=0;return(v);}
            if(v[1]<v_r[1]) v[1]=v_r[1];
        }
        // cout<<v[0]<<","<<v[1]<<","<<v[2]<<","<<endl;
        return(v);
        
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return(true);
        vector<int> v=helper(root);
        // cout<<v[0]<<","<<v[1]<<","<<v[2]<<","<<endl;
        return(v[2]==1);
    }
};