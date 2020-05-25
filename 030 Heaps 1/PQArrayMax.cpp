#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {10, 15, 4};
    priority_queue<int> pq(arr, arr+3);    // For vector pass v.begin(), v.end() 
    // This way is better instead of pushing elements one by one i.e. Build Heap
    // push and pop O(log N)
    // empty, size and top is O(1)

    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }


    return 0;
}
