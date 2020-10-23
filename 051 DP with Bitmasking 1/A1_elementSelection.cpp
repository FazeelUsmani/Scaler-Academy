/*

Element Selection
Problem Description

Given a matrix A of size N*N. You have to choose N elements from the matrix such that their sum is maximum but there is a catch.

You have to choose exactly one element from every row and every column. Return the maximum possible sum you can achieve by choosing N elements with the given condition.



Problem Constraints
1 <= N <= 18
-108 <= A[i][j] <= 108



Input Format
First and only argument is an integer matrix A.



Output Format
Return an integer denoting the maximum possible sum.



Example Input
Input 1:

 A = [ [5, 50], 
       [100, 10] ]
Input 2:

A = [ [1, 1],
      [10, 20] ]


Example Output
Output 1:

 150
Output 2:

 21


Example Explanation
Explanation 1:

 Choose 50 from 1st row and 100 from 2nd row.
Explanation 2:

 Choose first 1 from 1st row and 20 from 2nd row.

*/

#include <bits/stdc++.h>
using namespace std;

// Backtracking solution
int solve(vector<vector<int>> &A, int row, int mask)
{
    // cout << row << " " << mask << " " << ans << endl;
    if (row == A.size())
        return 0;
    int ans = INT_MIN;
    for (int col = 0; col < A.size(); ++col)
    {
        if ((mask >> col) & 1)
            continue;
        ans = max(ans, A[row][col] + solve(A, row + 1, (mask | (1 << col))));
    }
    return ans;
}

// Memoized solution
vector<vector<int>> dp(3, vector<int>(8, -1));

int solve1(vector<vector<int>> &A, int row, int mask)
{
    if (row == A.size())
        return 0;
    if (dp[row][mask] != -1)
        return dp[row][mask];
    int ans = INT_MIN;
    for (int col = 0; col < A[0].size(); ++col)
    {
        if (((mask >> col) & 1) == 1)
            continue;
        ans = max(ans, A[row][col] + solve1(A, row + 1, (mask | (1 << col))));
    }
    dp[row][mask] = ans;

    return ans;
}

int main()
{
    int ans = INT_MIN;
    vector<vector<int>> A{{1, 2, 5}, {1, 15, 20}, {2, 1, 10}};

    // Backtracking solution
    cout << "Ans is " << solve(A, 0, 0) << endl;

    // Memoized solution
    cout << "Memoized ans is " << solve1(A, 0, 0) << endl;

    return 0;
}