/*

0-1 Knapsack
Problem Description

Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


Problem Constraints
1 <= N <= 103

1 <= C <= 103

1 <= A[i], B[i] <= 103



Input Format
First argument is an integer array A of size N denoting the values on N items.

Second argument is an integer array B of size N denoting the weights on N items.

Third argument is an integer C denoting the knapsack capacity.



Output Format
Return a single integer denoting the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.



Example Input
Input 1:

 A = [60, 100, 120]
 B = [10, 20, 30]
 C = 50
Input 2:

 A = [10, 20, 30, 40]
 B = [12, 13, 15, 19]
 C = 10


Example Output
Output 1:

 220
Output 2:

 0


Example Explanation
Explanation 1:

 Taking items with weight 20 and 30 will give us the maximum value i.e 100 + 120 = 220
Explanation 2:

 Knapsack capacity is 10 but each item has weight greater than 10 so no items can be considered in the knapsack therefore answer is 0.


*/

int knapsack(vector<int>&A,vector<int>&B,int n,int C)
{
    int dp[n+1][C+1];
    
    for(int i=0;i<n+1;i++)
        for(int j=0;j<C+1;j++)
            if(i==0||j==0)
                dp[i][j]=0;
    
    for(int i=1;i<n+1;i++)
    for(int j=1;j<C+1;j++)
    {
        if(B[i-1]<=j)
        {
            dp[i][j] = max(A[i-1] + dp[i-1][j-B[i-1]],dp[i-1][j]);
        }else 
            dp[i][j] = dp[i-1][j];
    }
    
    return dp[n][C];
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    
    return knapsack(A,B,n,C);
}
