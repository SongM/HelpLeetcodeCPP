class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int> min_vals;
    MinStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
        if (min_vals.size()>0 and min_vals.back()<x) min_vals.push_back(min_vals.back());
        else min_vals.push_back(x);
    }
    
    void pop() {
        data.pop_back();
        min_vals.pop_back();
    }
    
    int top() {
        return(data.back());
    }
    
    int getMin() {
        return(min_vals.back());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */