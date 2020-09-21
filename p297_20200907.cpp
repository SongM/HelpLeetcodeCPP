/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        vector<TreeNode*> v_curr_level;
        v_curr_level.push_back(root);
        while(v_curr_level.size()>0)
        {
            vector<TreeNode*> v_prev_level = v_curr_level;
            v_curr_level = {};
            for (auto r:v_prev_level)
            {
                if (r==NULL)
                {
                    res += "N,";
                    continue;
                }
                res += to_string(r->val)+",";
                v_curr_level.push_back(r->left);
                v_curr_level.push_back(r->right);
           
            }
        }
        // cout<<res<<endl;
        return(res);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> v;
        string str = "";
        for (auto c:data)
        {
            if (c==',')
            {
                if (str=="N") v.push_back(NULL);
                else v.push_back(new TreeNode(stoi(str)));
                str = "";
            }
            else str += c;
        }
        int i=0;
        int j=1;
        for (int i=0;i<v.size();i++)
        {
            if (v[i]==NULL) continue;
            v[i]->left = v[j++];
            v[i]->right = v[j++];
        }
        return(v[0]);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));