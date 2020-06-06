/*

Max Sum Without Adjacent Elements

Problem Description

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers
are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.



Problem Constraints
1 <= N <= 20000
1 <= A[i] <= 2000



Input Format
The first and the only argument of input contains a 2d matrix, A.



Output Format
Return an integer, representing the maximum possible sum.



Example Input
Input 1:

 A = [   
        [1]
        [2]    
     ]
Input 2:

 A = [   
        [1, 2, 3, 4]
        [2, 3, 4, 5]    
     ]


Example Output
Output 1:

 2
Output 2:

 8


Example Explanation
Explanation 1:

 We will choose 2.
Explanation 2:

 We will choose 3 and 5.


*/


int Solution::adjacent(vector<vector<int> > &A) {
    
    int n = A[0].size();
    
    
    if (n == 1)
        return max(A[0][0], A[1][0]);
    if (n == 2)
        return max( max(A[0][0], A[1][0]), max(A[0][1], A[1][1]) );
    
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        arr[i] = max(A[0][i], A[1][i]);
        
    int coin[n] = {0};
    coin[0] = arr[0];
    coin[1] = max(arr[0], arr[1]);
    
    for (int i = 2; i < n; i++)
        coin[i] = max(coin[i-1], arr[i] + coin[i-2]);
        
    return coin[n-1];
}
