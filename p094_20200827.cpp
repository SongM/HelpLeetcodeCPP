//Inorder
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return(res);
        
        vector<TreeNode*> v;
        TreeNode* r=root;
        while(r!=NULL or v.size()>0){
            while (r!=NULL)
            {
                v.push_back(r);
                r=r->left;
            }
            r = v.back();
            v.pop_back();
            res.push_back(r->val);
            r = r->right;
            
        }
        return(res);
    }
};

class Solution {
public:
    void helper(vector<int>& res, TreeNode* r)
    {
        if (r==NULL) return;
        helper(res, r->left);
        res.push_back(r->val);
        helper(res, r->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res,root);
        return(res);
    }
};
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
