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
    vector<int> data;
    void helper(TreeNode* r)
    {
        if (r->right!=NULL) helper(r->right);
        data.push_back(r->val);
        if (r->left!=NULL) helper(r->left);
        return;
    }
    BSTIterator(TreeNode* root) {
        if (root!=NULL) helper(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int val=data.back();
        data.pop_back();
        return(val);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return(data.size()>0);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */