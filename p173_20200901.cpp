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
class BSTIterator {
public:
    vector<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        TreeNode* r = root;
        while(r!=NULL)
        {
            s.push_back(r);
            r = r->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* r=s.back();
        s.pop_back();
        int val = r->val;
        if (r->right!=NULL)
        {
            r = r->right;
            while(r!=NULL)
            {
                s.push_back(r);
                r = r->left;
            }            
        }
        return(val);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return(s.size()>0);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */