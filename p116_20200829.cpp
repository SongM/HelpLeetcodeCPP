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
        if (root==NULL or root->left==NULL) return(root);
        Node* r=root;
        Node* first = root;
        while(first!=NULL)
        {
            while (r!=NULL)
            {
                r->left->next = r->right;
                if (r->next!=NULL)
                    r->right->next = r->next->left;
                r=r->next;
            }
            r = first;
            first = first->left;
        }
        return(root);
        
    }
};