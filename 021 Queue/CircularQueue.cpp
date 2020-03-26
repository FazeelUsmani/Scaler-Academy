#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

class circularQ{
    private:
        int *arr;
        int size, f, r, capacity, count;
    public:
        circularQ(int size = SIZE);
        ~circularQ();

        bool isEmpty();
        int front1();
        void enqueue(int x);
        void dequeue();
};

circularQ::circularQ(int size){
    arr = new int[size];

    f = -1;
    r = -1;
    capacity = size;
    count = 0;

    cout<<"Creating CQ "<<count<<endl;
}

circularQ::~circularQ(){
    delete arr;
}

void circularQ::enqueue(int x){
    if ( (r+1)%size == f || count == capacity - 1){
        cout<<"Queue is full\n";
        exit(EXIT_FAILURE);
    }
    else if (isEmpty()){
        f = 0;
        r = 0;
        arr[r] = x;
        count = 1;
    }
    else    
    {
        r = (r+1)%capacity;
        arr[r] = x;           
        count++;
    }
    cout<<"Inserting "<<x<<" Size "<<count<<endl;
}

void circularQ::dequeue(){
    if (isEmpty())
        cout<<"Queue is Empty\n";
    else if (f == r){
        f = -1;
        r = -1;
        count = 0;
    }
    else{
        f = (f+1)%capacity;
        count--;
    }
    cout<<"Removing "<<front1()<<" Size "<<count<<endl;
}

int circularQ::front1(){
    return arr[f];
}

bool circularQ::isEmpty(){
    if (f == -1 && r == -1)
        return true;
    return false;
}

int main(){

    circularQ cq;

    cq.enqueue(10);
    cout<<cq.front1()<<endl;
    cq.enqueue(20);
    cout<<cq.front1()<<endl;
    cq.enqueue(30);
    cout<<cq.front1()<<endl;
    cq.enqueue(40);

    // cq.enqueue(50);
    // cq.enqueue(60); // Queue is Full

    cout<<cq.front1()<<endl<<"\n\n";

    while (!cq.isEmpty()){
        cout<<cq.front1()<<" ";
        cq.dequeue();
    }

    cout<<cq.front1()<<endl;

}
