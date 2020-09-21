/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return(NULL);
        vector<Node*> v;
        v.push_back(new Node(1));
        vector<Node*> s={node};
        while(s.size()>0)
        {
            Node* n = s.back();
            s.pop_back();
            if (v[n->val-1]->neighbors.size()>0) continue;
            for (auto neighb:n->neighbors)
            {
                if (neighb->val>=v.size()+1)
                {
                    for (int i=v.size()+1;i<=neighb->val;i++)
                        v.push_back(new Node(i));
                }
                v[n->val-1]->neighbors.push_back(v[neighb->val-1]);
                s.push_back(neighb);
            }
        }
        cout<<v.size();
        return(v[0]);
    }
};