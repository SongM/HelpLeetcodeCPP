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
    TreeNode* copytree(TreeNode* r,int start_i)
    {
        if (r==NULL) return(r);
        TreeNode* rr = new TreeNode(r->val+start_i);
        rr->left = copytree(r->left,start_i);
        rr->right = copytree(r->right,start_i);
        return(rr);
                
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {};
        vector<vector<TreeNode*>> v;
        v.push_back({NULL});
        for (int i=1;i<=n;i++)
        {
            v.push_back({});
            for (int k=0;k<i;k++)
            {
                for (auto rl:v[k])
                {
                    for (auto rr:v[i-k-1])
                    {
                        TreeNode* r = new TreeNode(k+1);
                        r->left = copytree(rl,0);
                        r->right = copytree(rr,k+1);
                        v[i].push_back(r);
                    }
                }
            }
        }
        return(v[n]);        
    }
};