//preorder
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        vector<int> res;
        while(v.size()>0)
        {
            TreeNode* r=v.back();
            v.pop_back();
            if (r==NULL) continue;
            res.push_back(r->val);
            v.push_back(r->right);
            v.push_back(r->left);
        }
        return(res);
    }
};

class Solution {
public:
    void helper(vector<int>& res, TreeNode* r)
    {
        if (r==NULL) return;
        res.push_back(r->val);
        helper(res,r->left);
        helper(res,r->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res,root);
        return(res);
    }
};
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
