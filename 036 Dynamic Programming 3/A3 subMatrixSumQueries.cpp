/*


Sub-matrix Sum Queries
Problem Description

Given a matrix of integers A of size N x M and multiple queries Q, for each query find and return the submatrix sum.

Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix whose sum is to find out.

NOTE:

Rows are numbered from top to bottom and columns are numbered from left to right.
Sum may be large so return the answer mod 109 + 7.


Problem Constraints
1 <= N, M <= 1000
-100000 <= A[i] <= 100000
1 <= Q <= 100000
1 <= B[i] <= D[i] <= N
1 <= C[i] <= E[i] <= M



Input Format
The first argument given is the integer matrix A.
The second argument given is the integer array B.
The third argument given is the integer array C.
The fourth argument given is the integer array D.
The fifth argument given is the integer array E.
(B[i], C[i]) represents the top left corner of the i'th query.
(D[i], E[i]) represents the bottom right corner of the i'th query.



Output Format
Return an integer array containing the submatrix sum for each query.



Example Input
Input 1:

 A = [   [1, 2, 3]
         [4, 5, 6]
         [7, 8, 9]   ]
 B = [1, 2]
 C = [1, 2]
 D = [2, 3]
 E = [2, 3]
Input 2:

 A = [   [5, 17, 100, 11]
         [0, 0,  2,   8]    ]
 B = [1, 1]
 C = [1, 4]
 D = [2, 2]
 E = [2, 4]


Example Output
Output 1:

 [12, 28]
Output 2:

 [22, 19]


Example Explanation
Explanation 1:

 For query 1: Submatrix contains elements: 1, 2, 4 and 5. So, their sum is 12.
 For query 2: Submatrix contains elements: 5, 6, 8 and 9. So, their sum is 28.
Explanation 2:

 For query 1: Submatrix contains elements: 5, 17, 0 and 0. So, their sum is 22.
 For query 2: Submatrix contains elements: 11 and 8. So, their sum is 19.
 


*/


vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) 
{
    
    int n = A.size(), m = A[0].size();
    
    long long int mod = 1000000007;
    
    long long int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++)
    {
        
        dp[i][0] = 0;
        
    }
    
    for(int i=0; i<=m; i++)
    {
        
        dp[0][i] = 0;
        
    }
    
    for(int i=1; i<=n; i++)
    {
        
        for(int j=1; j<=m; j++)
        {
            
            dp[i][j] = (mod + dp[i-1][j]%mod + dp[i][j-1]%mod + A[i-1][j-1]%mod - dp[i-1][j-1]%mod)%mod;
            
        }
        
    }
    
    vector<int> ans;
    
    for(int i=0; i<B.size(); i++)
    {
        
        int row1 = B[i];
        
        int col1 = C[i];
        
        int row2 = D[i];
        
        int col2 = E[i];
        
        int sum = (mod + dp[row2][col2]%mod - dp[row1 - 1][col2]%mod - dp[row2][col1 - 1]%mod + dp[row1 - 1][col1 - 1]%mod)%mod;
        
        if(sum < 0)
        {
            
            sum = sum + mod;
            
        }
        
        ans.push_back(sum%mod);
        
    }
    
    return ans;
    
}
