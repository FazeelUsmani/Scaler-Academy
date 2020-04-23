/*
Sum of minimum and maximum elements of all subarrays of size k
Given an array A of both positive and negative integers. Your task is to compute sum of minimum and maximum elements of 
all sub-array of size B. Note: Since the answer can be very large, you are required to return the sum module 1000000007. 

Input Format
The first argument denotes the array A.
The second argument denotes the value B

Output Format
Return an integer that denotes the required value.

Constraints
1 <= size of array A <= 100000
-1000000000 <= A[i] <= 1000000000
1 <= B <= size of array

** Example**
Example Input 1:
    A[] = {2, 5, -1, 7, -3, -1, -2}
    B = 4

Example Output 1:
    18
Explanation : 
    Subarrays of size 4 are : 
        {2, 5, -1, 7},   min + max = -1 + 7 = 6
        {5, -1, 7, -3},  min + max = -3 + 7 = 4      
        {-1, 7, -3, -1}, min + max = -3 + 7 = 4
        {7, -3, -1, -2}, min + max = -3 + 7 = 4   
        Sum of all min & max = 6 + 4 + 4 + 4 
                             = 18 
                             
                             */


int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    if (B == 1 || B == n)
        return 0;
    
    deque <int> dq;
    long long ans = 0;
    vector<int> res;

    for (int i = 0; i < n; i++){
        if (dq.empty())
            dq.push_back(i);

        else{
            while (!dq.empty() && A[i] > A[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        if (i + 1 >= B){
             while ( dq.front() <= i-B)
                dq.pop_front();

            ans += A[dq.front()];
        }       
    }
    
    while (!dq.empty())
        dq.pop_back();
    
    for (int i = 0; i < n; i++){
        if (dq.empty())
            dq.push_back(i);

        else{
            while (!dq.empty() && A[i] < A[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        if (i + 1 >= B){
             while ( dq.front() <= i-B)
                dq.pop_front();
            
            ans += A[dq.front()];
            
        }       
    }
    while (ans < 0)
        ans += 1000000007;
    
    ans %= 1000000007;
    return ans;
}
