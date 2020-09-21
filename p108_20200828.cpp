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
    TreeNode* helper(vector<int>& nums, int i, int j){
        int mi=i+(j-i)/2;
        TreeNode* r=new TreeNode(nums[mi]);
        if (i<mi) r->left = helper(nums,i,mi-1);
        if (mi<j) r->right = helper(nums,mi+1,j);
        return(r);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return(NULL);
        return(helper(nums,0,nums.size()-1));
    }
};