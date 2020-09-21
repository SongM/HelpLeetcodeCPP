/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==NULL) return(root);
        Node* r=root;
        Node* first = root;
        Node* curr;
        while(1)
        {
            r = first;
            curr=NULL;
            while(r!=NULL)
            {
                curr = r->left;
                if (curr!=NULL) break;
                curr = r->right;
                if (curr!=NULL) break;
                r = r->next;
            }
            if (curr==NULL) break;
            first = curr;
            if (r->left!=NULL and r->right!=NULL) 
            {
                curr->next = r->right;
                curr = curr->next;
            }
            r = r->next;
            while (r!=NULL)
            {
                if (r->left)
                {
                    curr->next = r->left;
                    curr = curr->next;
                }
                if (r->right)
                {
                    curr->next = r->right;
                    curr = curr->next;
                }
                r = r->next;
            }
        }
        return(root);

    }
};