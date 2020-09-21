void printMap(unordered_map<int,vector<int>> &m){
    for (auto it = m.begin();it != m.end(); ++it)
    {
        std::cout << it->first << ":" << it->second[0]<<","<<it->second[1] << "\n";
    }
    return;
}
struct doubleDirectListNode{
    int key;
    int val;
    doubleDirectListNode* next;
    doubleDirectListNode* prev;
    doubleDirectListNode(): key(0), val(0), next(NULL), prev(NULL) {}
    doubleDirectListNode(int _key, int _val): key(_key), val(_val), next(NULL), prev(NULL) {}
    doubleDirectListNode(int _key, int _val, doubleDirectListNode* _next, doubleDirectListNode* _prev): key(_key), val(_val), next(_next), prev(_prev) {}
};
void printDoubleDirectListNode(doubleDirectListNode* head, doubleDirectListNode* tail)
{
    doubleDirectListNode* h = head->next;
    while(h!=tail)
    {
        cout<<h->key<<','<<h->val<<"<-->";
        h=h->next;
    }
    cout<<endl;
    return;
}
class LRUCache {
public:
    int _capacity;
    doubleDirectListNode* head;
    doubleDirectListNode* tail;
    unordered_map<int, doubleDirectListNode*> data;
    LRUCache(int capacity) {
        head = new doubleDirectListNode();
        tail = new doubleDirectListNode();
        head->next = tail;
        tail->prev = head;
        _capacity = capacity;
    }
    
    int get(int key) {
        // cout<<"get"<<endl;
        if (data.find(key)==data.end()) return(-1);
        // printDoubleDirectListNode(head,tail);
        int value = data[key]->val;
        remove(key);
        // printDoubleDirectListNode(head,tail);
        addBeforeTail(key,value);
        // printDoubleDirectListNode(head,tail);
        return(value);
    }
    
    
    void remove(int key)
    {
        doubleDirectListNode* node = data[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        data.erase(data.find(key));
        return;
        
    }
    void addBeforeTail(int key, int value)
    {
        doubleDirectListNode* node = new doubleDirectListNode(key, value, tail, tail->prev);
        tail->prev->next = node;
        tail->prev = node;
        data[key] = node;
        return;
    }
    void put(int key, int value) {
        // cout<<"put"<<endl;
        if (data.find(key)==data.end()) 
        {
            addBeforeTail(key,value);
            if (_capacity==0) remove(head->next->key);
            else _capacity--;
        }
        else
        {
            remove(key);
            addBeforeTail(key,value);
        }
        // printDoubleDirectListNode(head,tail);
        return;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */