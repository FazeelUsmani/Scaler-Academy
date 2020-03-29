
#include <cstdlib>
#include <iostream>
using namespace std;

#define SIZE 10

class stack{
    int *arr;
    int top; 
    int capacity;
    int minEle;

    public:
        stack(int size = SIZE);
        ~stack();

        void push(int);
        int pop();

        int peek();
        int size();

        bool isEmpty();
        bool isFull();
        int getMin();

};

stack::stack(int size){
    arr = new int[size];
    capacity = size;
    top = -1;
    minEle = 10000;
}

stack::~stack(){
    delete arr;
}


void stack::push(int x){
    if (isFull()){
        cout<<"Overflow";
        //exit(EXIT_FAILURE);
    }
    cout<<" Inserting "<<x<<endl;
    if (x <= minEle){
        arr[++top] = x-minEle;
        minEle = x;
    }
    else{
        arr[++top] = x;
    }
}

int stack::pop(){
    if (isEmpty()){
        cout<<"Underflow ";
        //exit(EXIT_FAILURE);
    }
    cout<<"Removing "<<peek()<<endl;
    if (arr[top] < 0){
        minEle = minEle - arr[top];
    }
        
    return arr[top--];
}

int stack::peek(){
    if (isEmpty()){
        cout<<"No element in stack\n";
        //exit(EXIT_FAILURE);
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

int stack::getMin(){
    if (top == -1)
        return -1;
    cout<<" Top Index "<<top<<" \n Min Element is ";
    return minEle;
}


int main(){

    stack st(10);    

    st.push(2);
    st.push(1);
    cout<<st.peek();
    
    return 0;
}


