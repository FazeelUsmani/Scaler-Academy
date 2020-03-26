/*
Reversing the first B elements of queue

Given an array of integers A and an integer B. we need to reverse the order of the first B elements of the array,
leaving the other elements in the same relative order. Note: You are required to first insert elements into
an auxiliary queue then perform Reversal of first B elements. 

Input Format
The argument given is the integer array A and an integer B
Output Format
Return an array of integer after reversing the first k elements of A using queue

Constraints
1 <= B <= length of the array <= 200000
1 <= A[i] <= 100000
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 3
Output 1:
    [3, 2, 1, 4, 5]

Input 2:
    A = [5, 17, 100, 11]
    B = 2
Output 2:
    [17, 5, 100, 11]
    
  */
  
vector<int> Solution::solve(vector<int> &A, int B) {
    
    queue <int> q;
    int i = 0;
    for (i ; i < B; i++)
        q.push(A[i]);
    
    i--;
    
    while (i >= 0){
        A[i] = q.front();
        q.pop();
        i--;
    }
    
    return A;
}
  
