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
int arr[] = {10, 15, 4}; <br /> 
for (int &x : arr) <br /> 
    x = -x; <br /> 
priority_queue<int> pq(arr, arr+3);    // For vector pass v.begin(), v.end() <br /> 
while (!pq.empty()){ <br /> 
    cout<<-pq.top()<<" "; <br /> 
    pq.pop(); <br /> 
} <br /> 
<br /> 
priority_queue<int> pq(arr, arr+3);    // For vector pass v.begin(), v.end() <br />


__________________________________________________________________________________________

### Creating heap of pairs:
By default it considers the first element while creating a MAX/MIN heap. <br />
If you want to use 2nd element then you need to write your own custom comparator function <br />
