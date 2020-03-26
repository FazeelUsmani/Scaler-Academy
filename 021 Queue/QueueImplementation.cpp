#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

class Queue{
    private:
        int *arr;
        int size;
        int f;
        int r;
        
    public:
        Queue(int size = SIZE);
        ~Queue();

        void dequeue();
        void enqueue(int x);
        
        bool isEmpty();
        bool isFull();
        int front1();
};

Queue::Queue(int size){
    arr = new int[size];
    f = -1;
    r = -1;
}

Queue::~Queue(){
    delete arr;
}

void Queue::dequeue(){
    if(isEmpty())
        cout<<"Queue is empty\n";
    else if (f== r){
        f = -1;
        r = -1;
    }
    else
    {
        f++;
    }        
}

void Queue::enqueue(int x){
    if (r == size-1)
        cout<<"Queue is Full\n";
    else if (isEmpty()){
        f = 0;
        //r = 0;
        arr[++r] = x;
    }
    else
    {
        arr[++r] = x;
    }
}

bool Queue::isEmpty(){
    if (f == -1 && r == -1)
        return true;
    return false;
}

int Queue::front1(){
    return arr[f];
}



int main(){

    Queue q;

    q.enqueue(10);
    cout<<q.front1()<<endl;
    q.enqueue(20);
    cout<<q.front1()<<endl;
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(50);
    q.enqueue(50);

    cout<<q.front1()<<endl;

    while (!q.isEmpty()){
        cout<<q.front1()<<" ";
        q.dequeue();
    }
    

    return 0;
}
