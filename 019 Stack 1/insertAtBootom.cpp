// Here we're inserting the element at bottom of the stack

insertAtBottom(stack st, int x){
    if (st.isEmpty()){
        st.push(x);
        return;
    }
    else{
        int t = st.pop();
        insertAtBottom(st, x);
        st.push(t);
    }
    return st;
}
