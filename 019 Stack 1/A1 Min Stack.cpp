stack<int> st;
int minEle;

MinStack::MinStack() {
    while (!st.empty())
        st.pop();
    minEle = -1;
}

void MinStack::push(int x) {
    
    if (st.empty()){
        st.push(x);
        minEle = x;
    }
    else if (x <= minEle){
        st.push(2*x - minEle);
        minEle = x;
    }
    else
        st.push(x);        
}

void MinStack::pop() {
    
    if (st.empty())
        return;
        
    int x = st.top();
    st.pop();    
    if (x < minEle)
        minEle = 2*minEle - x;
    
}

int MinStack::top() {
    if (st.empty())
        return -1;
        
    int x = st.top();
    if (x < minEle)
        return minEle;
    return x;      
}

int MinStack::getMin() {
    if (st.empty())
        return -1;
    return minEle;
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
