#include<bits/stdc++.h>
using namespace std;


class MinHeap{
    
        int *arr;
        int size;
        int capacity;

    public:
        MinHeap (int capacity);        

        int left (int i){
            return 2*i+1;
        }

        int right (int i){
            return 2*i+2;
        }

        int parent (int i){
            return (i-1)/2;
        }
        void printHeap(){
            for (int i = 0; i < size; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        //void swap (int &a, int &b);
        void insert (int a);
        void minHeapify (int index);
        int extractMin();
        void decreaseKey(int i, int x);
        void deleteHeap(int i);
};

MinHeap::MinHeap(int x){
            arr = new int[x];
            size = 0;
            capacity = x;
        }

// void MinHeap::swap (int &a, int &b){
//     int x = a;
//     a = b;
//     b = x;
// }

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void MinHeap::insert (int x){
    if (size == capacity){
        cout<<"No more space to occupy!!!";
        return;
    }
    arr[size++] = x;
    for (int i = size-1; i != 0 && arr[parent(i)] > arr[i]; i++){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::minHeapify(int i){
    int lt = left(i), rt = right(i);
    int smallest = i;

    if (lt < size && arr[lt] < arr[i])
        smallest = lt;
    if (rt < size && arr[rt] < arr[smallest])
        smallest = rt;

    if (smallest < size && smallest != i){
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }
    else
    {
        return;
    }
}

int MinHeap::extractMin(){
    if (size <= 0){
        cout<<"Heap is Empty\n";
        return -1;
    }
    if (size == 1){                 //because we don't want to call minHeap for empty heap
        size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size-1];
    size--;
    minHeapify(0);   

    return root;
}

void MinHeap::decreaseKey(int i, int x){
    arr[i] = x;
    while (i != 0 && arr[parent(i)] > arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
    //minHeapify(0);        // No need of this statement because it is assumed new_val is smaller than arr[i]
}

void MinHeap::deleteHeap(int i){
    decreaseKey (i, INT_MIN);
    extractMin();
}


int main(){
    vector<int> arr{10,5,20,2,4,8};
    // Op: {2,4,8,5,10,20}

    int n = arr.size();
    MinHeap x(n);

    for (int i : arr)
        x.insert(i);
    x.printHeap();

    for (int i = (n-2)/2; i >= 0; i--)
        x.minHeapify(i);

    x.printHeap();

    // MinHeap a(10);    
    // a.insert(3);
    // a.insert(2);
    // a.insert(1);
    // a.insert(15);
    // a.insert(5);
    // a.insert(4);

    // cout<<"Start \n";
    // a.minHeapify(0);
    // a.printHeap();
    // cout<<"Min Ele is "<<a.extractMin()<<endl;
    // a.printHeap();
    // a.decreaseKey(3, 7);
    // a.printHeap();
    // a.deleteHeap(2);
    // a.printHeap();



    return 0;
}
