/*
First negative integer in window size B

Problem Description
Given an array of integers A of size N and an integer B. Find the first negative integer for each 
and every window(contiguous subarray) of size B. If a window does not contain a negative integer, 
then return 0 for that window. 


Problem Constraints
1 <= N <= 200000 -109 <= A[i] <= 109 


Input Format
The arguments given are integer array A and integer B.


Output Format
Return an integer array of size N+1-B representing answer of the ith window.


Example Input
 Input 1:
    A = [-1, 2, 3, -4, 5]
    B = 2
Input 2:
    A = [-8, 2, 3, -6, 10]
    B = 2
 


Example Output
Output 1:
    [-1, 0, -4, -4] 
Output 2:
    [-8, 0, -6, -6]


Example Explanation
Explaination For Input:-1 
    window [2,3] doesn't contain any negative integer so it's answer will be 0 and rest all the windows have some negative integer.
    
    */

vector<int> Solution::solve(vector<int> &A, int B) {
    
    deque<int> dq;
    vector<int> ans;
    int n = A.size();
    
    for (int i = 0; i < n; i++){
        
        if (A[i] < 0){
            dq.push_back(i);
        }
        if (i+1 >= B){
            while (!dq.empty() && dq.front() <= i - B)
                dq.pop_front();
            if (dq.empty())
                ans.push_back(0);
            else
                ans.push_back(A[dq.front()]);
        }
    }
    return ans;
    
}
