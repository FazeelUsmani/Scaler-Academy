## __C++__
### Max Heap: 
Syntax: priority_queue<int> pq; <br />
Syntax for conversion of already existing array: <br />
priority_queue<int> pq(arr, arr+3);    // For vector pass v.begin(), v.end() <br />
<br />
### Min Heap:<br />
Syntax: priority_queue<int, vector<int>, greater<int>> pq;<br />
Syntax for conversion of already existing array: <br />
you can use the same syntax but multiply with -1 to all elements in the array while building heap and printing it out<br />  

```cpp    
int arr[] = {10, 15, 4}; 
for (int &x : arr)  
    x = -x; 
priority_queue<int> pq(arr, arr+3);    // For vector pass v.begin(), v.end()
while (!pq.empty()){ 
    cout<<-pq.top()<<" ";
    pq.pop(); 
} 
priority_queue<int> pq(arr, arr+3);    // For vector pass v.begin(), v.end()
```
__________________________________________________________________________________________

### Creating heap of pairs:
By default it considers the first element while creating a MAX/MIN heap. <br />
If you want to use 2nd element then you need to write your own custom comparator function <br />

__________________________________________________________________________________________

## Applications:

1. Dijkstra Algorithm
2. Prim's Algorithm
3. Huffman Algorithm
4. Heap Sort

__________________________________________________________________________________________

## Some standard problems:

1. Sort K-Sorted Array
2. Buy Maximum items with Given Sum
3. K Largest Elements
4. Merge K-Sorted Arrays
5. Median of a Stream

