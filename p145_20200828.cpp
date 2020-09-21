//postorder
class Solution {
public:
    void helper(vector<int>& res, TreeNode* r)
    {
        if (r==NULL) return;
        helper(res,r->left);
        helper(res,r->right);
        res.push_back(r->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res,root);
        return(res);

    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        vector<int> res;
        while(v.size()>0)
        {
            TreeNode* r=v.back();
            v.pop_back();
            if (r==NULL) continue;
            res.push_back(r->val);
            v.push_back(r->left);
            v.push_back(r->right);
        }
        reverse(res.begin(),res.end());
        return(res);
    }
};
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


