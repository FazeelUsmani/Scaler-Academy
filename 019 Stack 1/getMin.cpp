class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    vector<int> minStack;
    
    MinStack() {
        st.clear();
        minStack.clear();
    }
    
    void push(int x) {
        st.push_back(x);
        if ( (minStack.size() == 0) || (minStack.back() >= x) )
            minStack.push_back(x);        
    }
    
    void pop() {
        if (st.size() == 0)
            return;
        int x = st.back();
        st.pop_back();
        if (minStack.back() == x)
            minStack.pop_back();        
    }
    
    int top() {
        if (st.size() == 0)
            return -1;
        return st.back();
    }
    
    int getMin() {
        if (minStack.size() > 0)
            return minStack.back();
        return -1;        
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
