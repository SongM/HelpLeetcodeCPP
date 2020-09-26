class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> data;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> t_data;
        while(data.size()>0)
        {
            t_data.push(data.top());
            data.pop();
        }
        data.push(x);
        while(t_data.size()>0)
        {
            data.push(t_data.top());
            t_data.pop();
        }
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = data.top();
        data.pop();
        return(res);
    }
    
    /** Get the front element. */
    int peek() {
        return(data.top());
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return(data.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */