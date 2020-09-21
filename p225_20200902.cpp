class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> data;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> t_data;
        while(data.size()>1)
        {
            t_data.push(data.front());
            data.pop();
        }
        int val = data.back();
        data.pop();
        while(t_data.size()>0)
        {
            data.push(t_data.front());
            t_data.pop();
        }
        return(val);
    }
    
    /** Get the top element. */
    int top() {
        return(data.back());
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return(data.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */