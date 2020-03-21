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





/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Here is the full program:- 
*/


#include <cstdlib>
#include <iostream>
using namespace std;

#define SIZE 10

class stack{
    int *arr;
    int top; 
    int capacity;

    public:
        stack(int size = SIZE);
        ~stack();

        void push(int);
        int pop();

        int peek();
        int size();

        bool isEmpty();
        bool isFull();
        stack insertAtBottom(stack, int);
};

stack::stack(int size){
    arr = new int[size];
    capacity = size;
    top = -1;
}

stack::~stack(){
    delete arr;
}


void stack::push(int x){
    if (isFull()){
        cout<<"Overflow";
        exit(EXIT_FAILURE);
    }
    cout<<" Inserting "<<x<<endl;
    arr[++top] = x;
}

int stack::pop(){
    if (isEmpty()){
        cout<<"Underflow ";
        exit(EXIT_FAILURE);
    }
    cout<<"Removing "<<peek()<<endl;
    return arr[top--];
}

int stack::peek(){
    if (isEmpty()){
        cout<<"No element is stack";
        exit(EXIT_FAILURE);
    }
    return arr[top];
}

int stack::size(){
    return top+1;
}
    

bool stack::isEmpty(){
    return top == -1;
}

bool stack::isFull(){
    return top == capacity-1;
}


stack stack::insertAtBottom(stack st, int x){
    if (st.isEmpty()){
        st.push(x);
        return st;
    }
    else{
        int t = st.pop();
        st.insertAtBottom(st, x);
        st.push(t);
    }
    return st;
}


int main(){

    stack st(5);    // Creating a stack of capacity 3

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout<<endl;

    st.insertAtBottom(st, 10);

    while (!st.isEmpty())
        st.pop();

    if (st.isEmpty())
        cout<<"Stack is empty";
    else
        cout<<"Stack is not empty";
    
   
    return 0;
}
