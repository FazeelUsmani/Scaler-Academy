Swap elements
Problem Description
Given an integer array A of size N. In the array, you can swap (A[i],A[j]) if the following conditions are satisfied:
i < j
i is a divisor of j
You are also provided M independent queries. In each query, you are given two integers idx and K. For each query, 
you are required to output the maximum number you can retrieve at index idx after performing at most K swaps.
NOTE 1: Queries are given by a 2-D integer array B of size M * 2 where B[i][0] denotes idx and B[i][1] denotes K. 
NOTE 2: Consider array A as 1-based indexed.      


Problem Constraints
1 <= N,M <= 50000
1 <= A[i] <= 109
1 <= B[i][0] <= N
0 <= B[i][1] <= 100


Input Format
First argument is an integer array A of size N.
Second argument is a 2-D integer array B of size M.


Output Format
Return an integer array of size M denoting output for each query as decribed above.


Example Input
A=[2,4,6,3,2]
B=[ [5,1]
    [4,1]
    [4,0] ]


Example Output
[2,4,3]


Example Explanation
For first query idx=5 and K=1. You can only swap element which is at index 1 (since 1 is the only divisor of 5 less than 5).
For second query idx=4 and K=1. You can swap element which is at index 1 or 2 (since 1 and 2 are the divisor of 4 less than 4).
For third query idx=4 and K=0. You cannot swap any element since K=0.


vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    
    A.insert(A.begin(), -1);
    int n = A.size();
    
    vector<int> val(n,0);
    int max_val = *max_element(A.begin(), A.end());
    
    for (int i = 1; i< n; i++){
        int mx = val[i];
        for (int j = i; j < n; j += i){
            val[j] = max(val[j], A[i]);
            mx = max(mx, A[j]);
        }
        val[i] = mx;
    }
    
    vector<int> ans;
    int m = B.size();
    for (int i = 0; i < m; i++){
        int idx = B[i][0];
        int k = B[i][1];
        
        if (k == 0)
            ans.push_back(A[idx]);
            
        else if (k > 1)
            ans.push_back(max_val);
            
        else
            ans.push_back(val[idx]);
    }
    return ans;
}
