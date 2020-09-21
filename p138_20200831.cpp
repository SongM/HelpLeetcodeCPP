/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return(NULL);
        unordered_map<Node*, Node*> m;        
        m[head] = new Node(head->val);
        m[NULL] = NULL;
        Node* n=head;
        while(n!=NULL)
        {
            if (m.find(n->next)==m.end()) m[n->next] = new Node(n->next->val);
            m[n]->next = m[n->next];
            if (m.find(n->random)==m.end()) m[n->random] = new Node(n->random->val);
            m[n]->random = m[n->random];
            n = n->next;
        }
        return(m[head]);
    }
};