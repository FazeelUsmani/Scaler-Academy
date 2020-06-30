/*

POWER ARRAYS
Given an array of integers A of size N.

An array is called POWER ARRAY if floor((maximum of array)/2) >= all other elements of array

Example:- A = [5, 3, 6, 13] is a POWER ARRAY because floor((13/2)) >= all other elements of the array.

Calculate how many subarrays of A are POWER ARRAYS.

NOTE : Single element can never be a power array.
Input Format

The first argument given is the integer array A.
Output Format

Calculate how many subarrays of A are POWER ARRAYS.
Constraints

1 <= N <= 100000
1 <= A[i] <= 100000
For Example

Input 1:
    A = [1, 2, 3, 4, 5 ]
Output 1:
    1
Explaination 1:
    Only subarray which is also a POWER ARRAY is [1, 2]

Input 2:
    A = [64, 32, 16, 8, 4]
Output 2:
    10
Explanation 1:
    All subarrays of size greater than 1 are POWER ARRAYs. 

*/


int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    int nge[n], pge[n];
    stack<int> s;
    s.push(0);
    
    for (int i = 1; i < n; ++i){
        while (!s.empty() && A[s.top()]/2 < A[i]){
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()){
        nge[s.top()] = n;
        s.pop();
    }
    
    s.push(n-1);
    for (int i = n-2; i >= 0; --i){
        while (!s.empty() && A[s.top()]/2 < A[i]){
            pge[ s.top() ] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()){
        pge[s.top()] = -1;
        s.pop();
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans += (nge[i]-i)*(i-pge[i]) - 1;
    }
    
    return ans;
}
