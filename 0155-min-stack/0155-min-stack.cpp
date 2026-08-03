class MinStack {
public:
    stack<int> st;
    stack<int> MIN;
    MinStack() {
        MIN.push(INT_MAX);
    }
    
    void push(int value) {
        st.push(value);
        MIN.push(min(MIN.top(),value));  
    }
    
    void pop() {
        if(!st.empty())
        {
            st.pop();
            MIN.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return MIN.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */